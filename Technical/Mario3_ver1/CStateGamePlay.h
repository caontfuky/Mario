#ifndef __CStateGamePlay_H__
#define __CStateGamePlay_H__
#include "CState.h"
#include "CSprite.h"
#include "CTexture.h"
#include <iostream>
#include "CMarioObject.h"
#include "CCollision.h"
#include "CPoolObject.h"
#include "CLoadBackground.h"
#include "CLoadObject.h"
#include"CLoadBackgroundMenu.h"

class CStateGamePlay : public CState
{
public:
	CStateGamePlay();
	CStateGamePlay(int mapId);
	virtual ~CStateGamePlay();
	void Init();
	void Update(float deltaTime);
	void Render();
	void Destroy();
public:
	int m_mapId;
	//CScenseManagement* m_scenseManager;
};

#endif // !__CStateGamePlay_H__

