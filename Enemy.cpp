#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"

CEnemy::CEnemy()
{
}

CEnemy::~CEnemy()
{
}

void CEnemy::SetPosition(float x, float y, float z)
{
	m_xmf3Position = XMFLOAT3(x, y, z);

	CGameObject::SetPosition(x, y, z);
}

void CEnemy::SetRotation(float x, float y, float z)
{
}



void CEnemy::Move(DWORD dwDirection, float fDistance)
{
	Move(XMFLOAT3(0, 0, 100), true);
}

void CEnemy::Move(XMFLOAT3& xmf3Shift, bool bUpdateVelocity)
{
	if (bUpdateVelocity) {
		m_xmf3Velocity = Vector3::Add(m_xmf3Velocity, xmf3Shift);
	}
	else {
		m_xmf3Position = Vector3::Add(xmf3Shift, m_xmf3Position);
	}

}

void CEnemy::Move(float x, float y, float z)
{
	Move(XMFLOAT3(x, y, z), false);
}

void CEnemy::Rotate(float fPitch, float fYaw, float fRoll)
{
	if (fPitch != 0.0f) {
		XMMATRIX mtxRotate = XMMatrixRotationAxis(XMLoadFloat3(&m_xmf3Right), XMConvertToRadians(fPitch));
		m_xmf3Look = Vector3::TransformNormal(m_xmf3Look, mtxRotate);
		m_xmf3Up = Vector3::TransformNormal(m_xmf3Up, mtxRotate);
	}
	if (fYaw != 0.0f) {
		XMMATRIX mtxRotate = XMMatrixRotationAxis(XMLoadFloat3(&m_xmf3Up), XMConvertToRadians(fYaw));
		m_xmf3Look = Vector3::TransformNormal(m_xmf3Look, mtxRotate);
		m_xmf3Right = Vector3::TransformNormal(m_xmf3Right, mtxRotate);
	}
	if (fRoll != 0.0f) {
		XMMATRIX mtxRotate = XMMatrixRotationAxis(XMLoadFloat3(&m_xmf3Look), XMConvertToRadians(fRoll));
		m_xmf3Up = Vector3::TransformNormal(m_xmf3Up, mtxRotate);
		m_xmf3Right = Vector3::TransformNormal(m_xmf3Right, mtxRotate);
	}
}

void CEnemy::LookAt(XMFLOAT3& xmf3LookAt, XMFLOAT3& xmf3Up)
{
	XMFLOAT4X4 xmf4x4View = Matrix4x4::LookAtLH(m_xmf3Position, xmf3LookAt, xmf3Up);
	m_xmf3Right = Vector3::Normalize(XMFLOAT3(xmf4x4View._11, xmf4x4View._21, xmf4x4View._31));
	m_xmf3Up = Vector3::Normalize(XMFLOAT3(xmf4x4View._12, xmf4x4View._22, xmf4x4View._32));
	m_xmf3Look = Vector3::Normalize(XMFLOAT3(xmf4x4View._13, xmf4x4View._23, xmf4x4View._33));
}

void CEnemy::Update(float fTimeElapsed)
{
	Move(m_xmf3Velocity, false);

	XMFLOAT3 xmf3Deceleration = Vector3::Normalize(Vector3::ScalarProduct(m_xmf3Velocity, -1.0f));
	float fLength = Vector3::Length(m_xmf3Velocity);
	float fDeceleration = m_fFriction * fTimeElapsed;
	if (fDeceleration > fLength)  fDeceleration = fLength;
	m_xmf3Velocity = Vector3::Add(m_xmf3Velocity, xmf3Deceleration, fDeceleration);

}

void CEnemy::DistanceToPlayer(CGameObject* player)
{
	float length = Vector3::Distance(player->GetPosition(),m_xmf3Position);
	if (length < 50.0f) {
		static int count = 0;
		if (count % 20 == 0 && m_blive) {
			CGameObject* pTemp{};
			((CEnemyTank*)this)->FireBullet(pTemp);
		}
		auto p = player->GetPosition();
		XMFLOAT3 posvec = Vector3::Subtract(player->GetPosition(), m_xmf3Position);
		LookAt(posvec, m_xmf3Up);
		++count;
	}
}


void CEnemy::Animate(float fElapsedTime)
{
	OnUpdateTransform();

	CGameObject::Animate(fElapsedTime);
}

void CEnemy::OnUpdateTransform()
{
	m_xmf4x4Transform._11 = m_xmf3Right.x; m_xmf4x4Transform._12 = m_xmf3Right.y; m_xmf4x4Transform._13 = m_xmf3Right.z;
	m_xmf4x4Transform._21 = m_xmf3Up.x; m_xmf4x4Transform._22 = m_xmf3Up.y; m_xmf4x4Transform._23 = m_xmf3Up.z;
	m_xmf4x4Transform._31 = m_xmf3Look.x; m_xmf4x4Transform._32 = m_xmf3Look.y; m_xmf4x4Transform._33 = m_xmf3Look.z;
	m_xmf4x4Transform._41 = m_xmf3Position.x; m_xmf4x4Transform._42 = m_xmf3Position.y; m_xmf4x4Transform._43 = m_xmf3Position.z;
}



void CEnemy::Render(HDC hDCFrameBuffer, CCamera* pCamera)
{
	CGameObject::Render(hDCFrameBuffer, pCamera);
}

CEnemyTank::CEnemyTank()
{
	CCubeMesh* pBodyMesh = new CCubeMesh(6.0f, 2.0f, 6.0f);
	SetMesh(pBodyMesh);
	SetColor(RGB(0, 0, 255));

	m_pTurret = new CGameObject();
	CCubeMesh* pTurretMesh = new CCubeMesh(4.0f, 1.5f, 4.0f);
	m_pTurret->SetMesh(pTurretMesh);
	m_pTurret->SetColor(RGB(255, 0, 0));
	m_pTurret->SetPosition(0.0f, 1.75f, 0.0f);
	SetChild(m_pTurret);

	m_pGun = new CGameObject();
	CCubeMesh* pGunMesh = new CCubeMesh(1.0f, 1.0f, 10.0f);
	m_pGun->SetMesh(pGunMesh);
	m_pGun->SetColor(RGB(255, 0, 255));
	m_pGun->SetPosition(0.0f, 3.25f, 4.0f);
	m_pGun->Rotate(5.f, 0, 0);
	SetChild(m_pGun);

	CCubeMesh* pBulletMesh = new CCubeMesh(1.0f, 1.0f, 4.0f);
	for (int i = 0; i < BULLETS; ++i) {
		m_ppBullets[i] = new CBulletObject(m_fBulletEffectiveRange);
		m_ppBullets[i]->SetMesh(pBulletMesh);
		m_ppBullets[i]->SetRotationAxis(XMFLOAT3(0.0f, 0.0f, 1.0f));
		m_ppBullets[i]->SetRotationSpeed(360.0f);
		m_ppBullets[i]->SetMovingSpeed(120.f);
		m_ppBullets[i]->SetActive(false);
	}

}

CEnemyTank::~CEnemyTank()
{
	for (int i = 0; i < BULLETS; i++) if (m_ppBullets[i]) delete m_ppBullets[i];
}

void CEnemyTank::Animate(float fElapsedTime)
{
	CEnemy::Animate(fElapsedTime);
	ComputeWorldTransform(NULL);

	UpdateBoundingBox();

	for (int i = 0; i < BULLETS; ++i) {
		if (m_ppBullets[i]->m_bActive) {

			m_ppBullets[i]->Animate(fElapsedTime);
			m_ppBullets[i]->ComputeWorldTransform(NULL);
		}
	}
}

void CEnemyTank::Render(HDC hDCFrameBuffer, CCamera* pCamera)
{
	CEnemy::Render(hDCFrameBuffer, pCamera);

	for (int i = 0; i < BULLETS; ++i)
		if (m_ppBullets[i]->m_bActive) {
			m_ppBullets[i]->Render(hDCFrameBuffer, pCamera);
		}
			
}


void CEnemyTank::FireBullet(CGameObject* pLockedObject)
{
	CBulletObject* pBulletObject = NULL;

	for (int i = 0; i < BULLETS; ++i) {
		if (!m_ppBullets[i]->m_bActive) {
			pBulletObject = m_ppBullets[i];
			break;
		}
	}

	if (pBulletObject) {
		XMFLOAT3 xmf3Position = m_pGun->GetPosition();
		XMFLOAT3 xmf3Direction = m_pGun->GetLook();
		XMFLOAT3 xmf3FirePosition = Vector3::Add(xmf3Position, Vector3::ScalarProduct(xmf3Direction, 6.0f, false));
		
		pBulletObject->m_xmf4x4Transform = m_pGun->m_xmf4x4World;

		pBulletObject->SetFirePosition(xmf3FirePosition);
		pBulletObject->SetMovingDirection(xmf3Direction);
		pBulletObject->SetColor(RGB(255, 0, 0));
		pBulletObject->SetActive(true);

		if (pLockedObject) {
			pBulletObject->m_pLockedObject = pLockedObject;
			pBulletObject->SetColor(RGB(0, 0, 255));
		}
	}
}

