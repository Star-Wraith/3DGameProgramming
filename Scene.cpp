#include "stdafx.h"
#include "Scene.h"
#include "GraphicsPipeline.h"
#include "Enemy.h"

CScene::CScene(CPlayer* pPlayer)
{
	m_pPlayer = pPlayer;
}

CScene::~CScene()
{
}

void CScene::BuildObjects()
{


	PlaySound(TEXT("EyesofGlory.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	CExplosiveObject::PrepareExplosion();

	float fHalfWidth = 45.0f, fHalfHeight = 45.0f, fHalfDepth = 200.0f;
	CFloorMesh* pFloorMesh = new CFloorMesh(fHalfWidth * 2.0f, fHalfDepth * 2.0f, 30);

	m_pFloorObject = new CFloorObject();
	m_pFloorObject->SetPosition(0.0f, 0.0f, 0.0f);
	m_pFloorObject->SetMesh(pFloorMesh);
	m_pFloorObject->SetColor(RGB(0, 0, 0));
	m_pFloorObject->m_pxmf4FloorPlane = XMFLOAT4(0.0f, +1.0f, 0.0f, 0.0f);

	CCubeMesh* pCubeMesh = new CCubeMesh(4.0f, 4.0f, 4.0f);

	m_nObjects = 38;
	m_ppObjects = new CGameObject * [m_nObjects];

	// 장애물 생성 부분 ==================================================
	int nindex = 0;
	CExplosiveObject *pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-43.5f, 0.0f, -44.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(90.0f);
	pExplosiveObject->SetName("ExObject");
	m_ppObjects[nindex] = pExplosiveObject;


	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(0, 0, 255));
	pExplosiveObject->SetPosition(+43.5f, 0.0f, -44.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(180.0f);
	pExplosiveObject->SetName("ExObject");
	m_ppObjects[++nindex] = pExplosiveObject;


	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(0, 255, 0));
	pExplosiveObject->SetPosition(-43.5f, 0.0f, +44.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(30.15f);
	pExplosiveObject->SetName("ExObject");
	m_ppObjects[++nindex] = pExplosiveObject;


	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(0, 255, 255));
	pExplosiveObject->SetPosition(+43.5f, 0.0f, +44.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(40.6f);
	pExplosiveObject->SetName("ExObject");
	m_ppObjects[++nindex] = pExplosiveObject;


	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(128, 0, 255));
	pExplosiveObject->SetPosition(0.0f, 0.0f, 40.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(50.06f);
	pExplosiveObject->SetName("ExObject");
	m_ppObjects[++nindex] = pExplosiveObject;


	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 255));
	pExplosiveObject->SetPosition(-20.0f, 0.0f, -20.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(60.06f);
	pExplosiveObject->SetName("ExObject");
	m_ppObjects[++nindex] = pExplosiveObject;


	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 255));
	pExplosiveObject->SetPosition(-20.0f, 0.0f, +20.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(60.06f);
	pExplosiveObject->SetName("ExObject");
	m_ppObjects[++nindex] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 128));
	pExplosiveObject->SetPosition(+20.0f, 0.0f, -20.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(70.06f);
	pExplosiveObject->SetName("ExObject");
	m_ppObjects[++nindex] = pExplosiveObject;


	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(128, 0, 255));
	pExplosiveObject->SetPosition(+20.0f, 0.0f, +20.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(90.06f);
	pExplosiveObject->SetName("ExObject");
	m_ppObjects[++nindex] = pExplosiveObject;


	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 64, 64));
	pExplosiveObject->SetPosition(+15.0f, 0.0f, 0.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(70.06f);
	pExplosiveObject->SetName("ExObject");
	m_ppObjects[++nindex] = pExplosiveObject;


	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 128, 128));
	pExplosiveObject->SetPosition(30.0f, 1.0f, 80.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(90.06f);
	pExplosiveObject->SetName("ExObject");
	m_ppObjects[++nindex] = pExplosiveObject;


	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(128, 255, 128));
	pExplosiveObject->SetPosition(10.0f, 1.0f, 80.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(70.06f);
	pExplosiveObject->SetName("ExObject");
	m_ppObjects[++nindex] = pExplosiveObject;


	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(128, 128, 255));
	pExplosiveObject->SetPosition(-30.0f, 1.0f, 80.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(50.06f);
	pExplosiveObject->SetName("ExObject");
	m_ppObjects[++nindex] = pExplosiveObject;


	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(50, 27, 115));
	pExplosiveObject->SetPosition(-10, 1.0f, 80.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(30.06f);
	pExplosiveObject->SetName("ExObject");
	m_ppObjects[++nindex] = pExplosiveObject;


	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 64, 64));
	pExplosiveObject->SetPosition(0.0f, 1.0f, 110.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(90.06f);
	pExplosiveObject->SetName("ExObject");
	m_ppObjects[++nindex] = pExplosiveObject;


	// 장애물 생성 부분 끝 ==================================================
	int nEx = nindex;

	// Tank 생성 부분  =================================================
	CEnemyTank* pEnemyTankObject = new CEnemyTank();
	pEnemyTankObject->SetPosition(0.0f, 1.0f, 100.0f);
	pEnemyTankObject->SetMovingSpeed(-5);
	pEnemyTankObject->SetName("EnemyTank0");
	m_ppObjects[++nEx] = pEnemyTankObject;

	pEnemyTankObject = new CEnemyTank();
	pEnemyTankObject->SetPosition(40.0f, 1.0f, 100.0f);
	pEnemyTankObject->SetMovingSpeed(-5);
	pEnemyTankObject->SetName("EnemyTank0");
	m_ppObjects[++nEx] = pEnemyTankObject;


	pEnemyTankObject = new CEnemyTank();
	pEnemyTankObject->SetPosition(-40.0f, 1.0f, 100.0f);
	pEnemyTankObject->SetMovingSpeed(-5);
	pEnemyTankObject->SetName("EnemyTank0");
	m_ppObjects[++nEx] = pEnemyTankObject;

	pEnemyTankObject = new CEnemyTank();
	pEnemyTankObject->SetPosition(-30.0f, 1.0f, 150.0f);
	pEnemyTankObject->SetMovingSpeed(-5);
	pEnemyTankObject->SetName("EnemyTank0");
	m_ppObjects[++nEx] = pEnemyTankObject;

	pEnemyTankObject = new CEnemyTank();
	pEnemyTankObject->SetPosition(30.0f, 1.0f, 150.0f);
	pEnemyTankObject->SetMovingSpeed(-5);
	pEnemyTankObject->SetName("EnemyTank0");
	m_ppObjects[++nEx] = pEnemyTankObject;

	// Tank 생성 부분 끝 =================================================
	int nExTank = nEx;



	// Clear 생성 부분 =================================================

	pCubeMesh = new CCubeMesh(10.0f, 4.0f, 2.0f); // C에서  위에 ㅡ
	CGameObject* pClear = new CGameObject();
	pClear->SetPosition(-30.f, 20.f, 70.f);
	pClear->SetMesh(pCubeMesh);
	pClear->SetColor(RGB(255, 255, 255));
	pClear->SetName("Clear");
	m_ppObjects[++nExTank] = pClear;

	pCubeMesh = new CCubeMesh(4.0f, 10.0f, 2.0f); // C에서  옆에 |
	pClear = new CGameObject();
	pClear->SetPosition(-37.f, 15.f, 70.f);
	pClear->SetMesh(pCubeMesh);
	pClear->SetColor(RGB(255, 255, 255));
	pClear->SetName("Clear");
	m_ppObjects[++nExTank] = pClear;

	pCubeMesh = new CCubeMesh(10.0f, 4.0f, 2.0f); // C에서  밑에 ㅡ
	pClear = new CGameObject();
	pClear->SetPosition(-30.f, 10.f, 70.f);
	pClear->SetMesh(pCubeMesh);
	pClear->SetColor(RGB(255, 255, 255));
	pClear->SetName("Clear");
	m_ppObjects[++nExTank] = pClear;

	pCubeMesh = new CCubeMesh(4.0f, 15.0f, 2.0f); // L에서  옆에 |
	pClear = new CGameObject();
	pClear->SetPosition(-18.f, 15.f, 70.f);
	pClear->SetMesh(pCubeMesh);
	pClear->SetColor(RGB(255, 255, 255));
	pClear->SetName("Clear");
	m_ppObjects[++nExTank] = pClear;

	pCubeMesh = new CCubeMesh(10.0f, 4.0f, 2.0f); // L에서  옆에 ㅡ
	pClear = new CGameObject();
	pClear->SetPosition(-11.8f, 9.6f, 70.f);
	pClear->SetMesh(pCubeMesh);
	pClear->SetColor(RGB(255, 255, 255));
	pClear->SetName("Clear");
	m_ppObjects[++nExTank] = pClear;

	pCubeMesh = new CCubeMesh(10.0f, 4.0f, 2.0f); // E에서  위에 ㅡ
	pClear = new CGameObject();
	pClear->SetPosition(6.5f, 20.f, 70.f);
	pClear->SetMesh(pCubeMesh);
	pClear->SetColor(RGB(255, 255, 255));
	pClear->SetName("Clear");
	m_ppObjects[++nExTank] = pClear;

	pCubeMesh = new CCubeMesh(4.0f, 14.0f, 2.0f); // E에서  옆에 |
	pClear = new CGameObject();
	pClear->SetPosition(0.f, 15.f, 70.f);
	pClear->SetMesh(pCubeMesh);
	pClear->SetColor(RGB(255, 255, 255));
	pClear->SetName("Clear");
	m_ppObjects[++nExTank] = pClear;

	pCubeMesh = new CCubeMesh(10.0f, 4.0f, 2.0f); // E에서  중간에 ㅡ
	pClear = new CGameObject();
	pClear->SetPosition(6.5f, 15.f, 70.f);
	pClear->SetMesh(pCubeMesh);
	pClear->SetColor(RGB(255, 255, 255));
	pClear->SetName("Clear");
	m_ppObjects[++nExTank] = pClear;

	pCubeMesh = new CCubeMesh(10.0f, 4.0f, 2.0f); // E에서  밑에 ㅡ
	pClear = new CGameObject();
	pClear->SetPosition(6.5f, 10.f, 70.f);
	pClear->SetMesh(pCubeMesh);
	pClear->SetColor(RGB(255, 255, 255));
	pClear->SetName("Clear");
	m_ppObjects[++nExTank] = pClear;

	pCubeMesh = new CCubeMesh(4.0f, 14.0f, 2.0f); // A에서  왼쪽에 |
	pClear = new CGameObject();
	pClear->SetPosition(20.f, 15.f, 70.f);
	pClear->SetMesh(pCubeMesh);
	pClear->SetColor(RGB(255, 255, 255));
	pClear->SetName("Clear");
	m_ppObjects[++nExTank] = pClear;

	pCubeMesh = new CCubeMesh(6.0f, 4.0f, 2.0f); // A에서  위에 ㅡ
	pClear = new CGameObject();
	pClear->SetPosition(24.5f, 21.f, 70.f);
	pClear->SetMesh(pCubeMesh);
	pClear->SetColor(RGB(255, 255, 255));
	pClear->SetName("Clear");
	m_ppObjects[++nExTank] = pClear;

	pCubeMesh = new CCubeMesh(6.0f, 4.0f, 2.0f); // A에서  밑에 ㅡ
	pClear = new CGameObject();
	pClear->SetPosition(24.5f, 14.f, 70.f);
	pClear->SetMesh(pCubeMesh);
	pClear->SetColor(RGB(255, 255, 255));
	pClear->SetName("Clear");
	m_ppObjects[++nExTank] = pClear;

	pCubeMesh = new CCubeMesh(4.0f, 14.0f, 2.0f); // A에서  오른쪽에 |
	pClear = new CGameObject();
	pClear->SetPosition(29.f, 15.f, 70.f);
	pClear->SetMesh(pCubeMesh);
	pClear->SetColor(RGB(255, 255, 255));
	pClear->SetName("Clear");
	m_ppObjects[++nExTank] = pClear;

	pCubeMesh = new CCubeMesh(4.0f, 14.0f, 2.0f); // R에서  왼쪽에 |
	pClear = new CGameObject();
	pClear->SetPosition(40.f, 15.f, 70.f);
	pClear->SetMesh(pCubeMesh);
	pClear->SetColor(RGB(255, 255, 255));
	pClear->SetName("Clear");
	m_ppObjects[++nExTank] = pClear;

	pCubeMesh = new CCubeMesh(6.0f, 4.0f, 2.0f); // R에서  위에 ㅡ
	pClear = new CGameObject();
	pClear->SetPosition(44.5f, 20.f, 70.f);
	pClear->SetMesh(pCubeMesh);
	pClear->SetColor(RGB(255, 255, 255));
	pClear->SetName("Clear");
	m_ppObjects[++nExTank] = pClear;

	pCubeMesh = new CCubeMesh(6.0f, 4.0f, 2.0f); // R에서  밑에 ㅡ
	pClear = new CGameObject();
	pClear->SetPosition(44.5f, 14.f, 70.f);
	pClear->SetMesh(pCubeMesh);
	pClear->SetColor(RGB(255, 255, 255));
	pClear->SetName("Clear");
	m_ppObjects[++nExTank] = pClear;

	pCubeMesh = new CCubeMesh(4.0f, 6.0f, 2.0f); // R에서  오른쪽에 ㅣ
	pClear = new CGameObject();
	pClear->SetPosition(49.f, 18.f, 70.f);
	pClear->SetMesh(pCubeMesh);
	pClear->SetColor(RGB(255, 255, 255));
	pClear->SetName("Clear");
	m_ppObjects[++nExTank] = pClear;

	pCubeMesh = new CCubeMesh(4.0f, 6.0f, 2.0f); // R에서  오른쪽에 ㅣ
	pClear = new CGameObject();
	pClear->SetPosition(49.f, 10.8f, 70.f);
	pClear->SetMesh(pCubeMesh);
	pClear->SetColor(RGB(255, 255, 255));
	pClear->SetName("Clear");
	m_ppObjects[++nExTank] = pClear;

	// Clear 생성 부분 끝 =================================================


#ifdef _WITH_DRAW_AXIS
	m_pWorldAxis = new CGameObject();
	CAxisMesh* pAxisMesh = new CAxisMesh(0.5f, 0.5f, 0.5f);
	m_pWorldAxis->SetMesh(pAxisMesh);
#endif
}

void CScene::ReleaseObjects()
{
	if (CExplosiveObject::m_pExplosionMesh) CExplosiveObject::m_pExplosionMesh->Release();

	for (int i = 0; i < m_nObjects; i++) if (m_ppObjects[i]) delete m_ppObjects[i];
	if (m_ppObjects) delete[] m_ppObjects;

	if (m_pFloorObject) delete m_pFloorObject;

#ifdef _WITH_DRAW_AXIS
	if (m_pWorldAxis) delete m_pWorldAxis;
#endif
}

void CScene::OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
}

void CScene::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	switch (nMessageID)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			CExplosiveObject* pExplosiveObject = (CExplosiveObject*)m_ppObjects[int(wParam - '1')];
			pExplosiveObject->m_bBlowingUp = true;
			m_pPlayer->SetHP(10);
			break;
		}
		case 'A':
			for (int i = 0; i < m_nObjects; i++)
			{
				if (m_ppObjects[i]->GetName() == "ExObject") {
					CExplosiveObject* pExplosiveObject = (CExplosiveObject*)m_ppObjects[i];
					pExplosiveObject->m_bBlowingUp = true;
				}

			}
			m_pPlayer->SetHP(80);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

CGameObject* CScene::PickObjectPointedByCursor(int xClient, int yClient, CCamera* pCamera)
{
	XMFLOAT3 xmf3PickPosition;
	xmf3PickPosition.x = (((2.0f * xClient) / (float)pCamera->m_Viewport.m_nWidth) - 1) / pCamera->m_xmf4x4PerspectiveProject._11;
	xmf3PickPosition.y = -(((2.0f * yClient) / (float)pCamera->m_Viewport.m_nHeight) - 1) / pCamera->m_xmf4x4PerspectiveProject._22;
	xmf3PickPosition.z = 1.0f;

	XMVECTOR xmvPickPosition = XMLoadFloat3(&xmf3PickPosition);
	XMMATRIX xmmtxView = XMLoadFloat4x4(&pCamera->m_xmf4x4View);

	int nIntersected = 0;
	float fNearestHitDistance = FLT_MAX;
	CGameObject* pNearestObject = NULL;
	for (int i = 0; i < m_nObjects; i++)
	{
		float fHitDistance = FLT_MAX;
		nIntersected = m_ppObjects[i]->PickObjectByRayIntersection(xmvPickPosition, xmmtxView, &fHitDistance);
		if ((nIntersected > 0) && (fHitDistance < fNearestHitDistance))
		{
			fNearestHitDistance = fHitDistance;
			pNearestObject = m_ppObjects[i];
		}
	}
	return(pNearestObject);
}

void CScene::CheckObjectByObjectCollisions()
{
	for (int i = 0; i < m_nObjects; i++) m_ppObjects[i]->m_pObjectCollided = NULL;
	for (int i = 0; i < m_nObjects; i++)
	{
		for (int j = (i + 1); j < m_nObjects; j++)
		{
			if (m_ppObjects[i]->m_xmOOBB.Intersects(m_ppObjects[j]->m_xmOOBB))
			{
				m_ppObjects[i]->m_pObjectCollided = m_ppObjects[j];
				m_ppObjects[j]->m_pObjectCollided = m_ppObjects[i];
			}
		}
	}

}

void CScene::CheckObjectByBulletCollisions()
{
	CBulletObject** ppBullets = ((CTankPlayer*)m_pPlayer)->m_ppBullets;
	for (int i = 0; i < m_nObjects; i++)
	{
		for (int j = 0; j < BULLETS; j++)
		{


			if (ppBullets[j]->m_bActive && m_ppObjects[i]->m_xmOOBB.Intersects(ppBullets[j]->m_xmOOBB))
			{
				auto p = m_ppObjects[i]->GetName(); // 디버깅 확인용
				if (p == "EnemyTank0") {
					m_ppObjects[i]->SetHP(10);

					if (m_ppObjects[i]->GetHP() == 0) {
						XMFLOAT3 xmf3temp = m_ppObjects[i]->GetPosition();
						m_ppObjects[i]->SetMovingSpeed(0.0f);
						m_ppObjects[i]->SetPosition(xmf3temp.x, xmf3temp.y, xmf3temp.z);
						m_ppObjects[i]->SetColor(RGB(0, 0, 0));
						m_ppObjects[i]->m_pChild->SetColor(RGB(0, 0, 0));
						m_ppObjects[i]->m_pChild->m_pSibling->SetColor(RGB(0, 0, 0));
						((CEnemy*)m_ppObjects[i])->m_blive = false;


					}
					
				}
				else {
					CExplosiveObject* pExplosiveObject = (CExplosiveObject*)m_ppObjects[i];
					if (pExplosiveObject->m_bBlowingUp == false) {
						pExplosiveObject->m_bBlowingUp = true;
						m_pPlayer->SetHP(20);

						if (m_pPlayer->GetHP() <= 0) {
							SetScenefalse();

						}
					}

				}
				ppBullets[j]->Reset();
			}


		}

		if (m_ppObjects[i]->GetName() == "EnemyTank0") {

			CBulletObject** ppBulletsEnemy = ((CEnemyTank*)m_ppObjects[i])->m_ppBullets;
			for (int j = 0; j < BULLETS; j++)
			{
				if (ppBulletsEnemy[j]->m_bActive && m_pPlayer->m_xmOOBB.Intersects(ppBulletsEnemy[j]->m_xmOOBB)) {
					m_pPlayer->SetHP(10);

					if (m_pPlayer->GetHP() <= 0) {
						SetScenefalse();

					}


				}
			}
		}
	}
}

void CScene::Animate(float fElapsedTime)
{
	
	m_pFloorObject->Animate(fElapsedTime);
	m_pFloorObject->ComputeWorldTransform(NULL);

	m_pPlayer->m_xmf3Position.x = std::clamp(m_pPlayer->m_xmf3Position.x, -40.f, 40.f);
	m_pPlayer->m_xmf3Position.z = std::clamp(m_pPlayer->m_xmf3Position.z, -20.f, 40.f);

/*수정*/
	int enemyLifeCount = 0;
	for (int i = 0; i < m_nObjects; i++)
	{
		if (m_ppObjects[i]->GetName() == "EnemyTank0") {
			
			if (((CEnemy*)m_ppObjects[i])->m_blive == true) {
				++enemyLifeCount;
				m_ppObjects[i]->DistanceToPlayer(m_pPlayer);
				if (((CEnemy*)m_ppObjects[i])->GetPosition().z < -50.f) {
					SetScenefalse();
				}
			}
		}
		if (m_ppObjects[i]->GetName() == "Clear") {
			if (enemyLifeCount == 0) {
				m_ppObjects[i]->SetColor(RGB(0, 0, 0));
			}
		}

		m_ppObjects[i]->Animate(fElapsedTime);
		m_ppObjects[i]->ComputeWorldTransform(NULL);
		m_ppObjects[i]->UpdateBoundingBox();
	}

	CheckObjectByObjectCollisions();

	CheckObjectByBulletCollisions();
}

void CScene::Render(HDC hDCFrameBuffer, CCamera* pCamera)
{
	CGraphicsPipeline::SetViewport(&pCamera->m_Viewport);
	CGraphicsPipeline::SetViewPerspectiveProjectTransform(&pCamera->m_xmf4x4ViewPerspectiveProject);

	m_pFloorObject->Render(hDCFrameBuffer, pCamera);
	for (int i = 0; i < m_nObjects; i++) m_ppObjects[i]->Render(hDCFrameBuffer, pCamera);

	if (m_pPlayer) m_pPlayer->Render(hDCFrameBuffer, pCamera);

//UI
#ifdef _WITH_DRAW_AXIS
	CGraphicsPipeline::SetViewOrthographicProjectTransform(&pCamera->m_xmf4x4ViewOrthographicProject);
	m_pWorldAxis->SetRotationTransform(&m_pPlayer->m_xmf4x4World);
	m_pWorldAxis->Render(hDCFrameBuffer, pCamera);
#endif
}


