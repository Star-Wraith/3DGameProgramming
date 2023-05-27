#pragma once

#include "GameObject.h"
#include "Camera.h"
#include "Player.h"

class CScene
{
public:
	CScene(CPlayer *pPlayer);
	virtual ~CScene();

private:
	int							m_nObjects = 0;
	bool						m_Scene_life = true;
	CGameObject					**m_ppObjects = NULL;

	CFloorObject*				m_pFloorObject = NULL;

	CPlayer*					m_pPlayer = NULL;


	int							dwID;

#ifdef _WITH_DRAW_AXIS
	CGameObject*				m_pWorldAxis = NULL;
#endif

public:
	virtual void BuildObjects();
	virtual void ReleaseObjects();

	void SetScenefalse() { m_Scene_life = false; }
	bool GetScenefalse() const { return m_Scene_life; }

	void CheckObjectByObjectCollisions();
	void CheckObjectByBulletCollisions();

	virtual void Animate(float fElapsedTime);
	virtual void Render(HDC hDCFrameBuffer, CCamera* pCamera);

	virtual void OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	virtual void OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);

	CGameObject* PickObjectPointedByCursor(int xClient, int yClient, CCamera* pCamera);
};

