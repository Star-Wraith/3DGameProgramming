#pragma once
#include "GameObject.h"

class CPlayer;

class CEnemy :
    public CGameObject
{
public:
    CEnemy();
    virtual ~CEnemy();

public:

    XMFLOAT3        m_xmf3Position = XMFLOAT3(0.0f, 0.0f, 0.0f);
    XMFLOAT3        m_xmf3Right = XMFLOAT3(1.0f, 0.0f, 0.0f);
    XMFLOAT3        m_xmf3Up = XMFLOAT3(0.0f, 1.0f, 0.0f);
    XMFLOAT3        m_xmf3Look = XMFLOAT3(0.0f, 0.0f, -1.0f);

    XMFLOAT3        m_xmf3Velocity = XMFLOAT3(0.0f, 0.0f, -1.0f);

    float           m_fFriction = 125.0f;

    int             m_HP = 100;

    bool            m_blive = true;

    float           m_fPitch = 0.0f;
    float           m_fYaw = 0.0f;
    float           m_fRoll = 0.0f;

    CCamera*        m_pCamera = NULL;

public:

    void SetPosition(float x, float y, float z);
    void SetRotation(float x, float y, float z);
    virtual void SetHP(int AttackedPower) { m_HP -= AttackedPower; }
    virtual int GetHP() const { return m_HP; }
    

    void LookAt(XMFLOAT3& xmf3LookAt, XMFLOAT3& xmf3Up);

    void Move(DWORD dwDirection, float fDistance);
    void Move(XMFLOAT3& xmf3Shift, bool bUpdateVelocity);
    void Move(float x, float y, float z);

    void Rotate(float fPitch = 0.0f, float fYaw = 0.0f, float fRoll = 0.0f);

    void Update(float fTimeElapsed = 0.016f);

    virtual void DistanceToPlayer(CGameObject* player);

    virtual void OnUpdateTransform();
    virtual void Animate(float fElapsedTime);
    virtual void Render(HDC hDCFrameBuffer, CCamera* pCamera);


};
#define BULLETS					250

class CEnemyTank : public CEnemy {
public:
    CEnemyTank();
    virtual ~CEnemyTank();

    CGameObject*              m_pTurret = NULL;
    CGameObject*              m_pGun = NULL;

    float                     m_fBulletEffectiveRange = 150.0f;
    CBulletObject*            m_ppBullets[BULLETS];

    void RotateTurret(float fAngle) { m_pTurret->Rotate(0.0f, fAngle, 0.0f); }
    void RotateGun(float fAngle) { m_pGun->Rotate(fAngle, 0.0f, 0.0f); }
    
    void FireBullet(CGameObject* pLockedObject);
    
    
    virtual void Animate(float fElapsedTime);
    virtual void Render(HDC hDCFrameBuffer, CCamera* pCamera);
};