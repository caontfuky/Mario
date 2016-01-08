#pragma once
#include"CState.h"
#include "CLoadWorldMap.h"
class CWorldMapScene:public CState
{
public:
	CWorldMapScene();
	~CWorldMapScene();

	CLoadWorldMap* worldMap;

	void Init();
	void Update(float deltaTime);
	void Render();
	void Destroy();
};

