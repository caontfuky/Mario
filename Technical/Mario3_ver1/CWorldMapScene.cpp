#include "CWorldMapScene.h"


CWorldMapScene::CWorldMapScene()
{
	Init();
}


CWorldMapScene::~CWorldMapScene()
{
}
void CWorldMapScene::Init()
{
	this->worldMap = new CLoadWorldMap();
}
void CWorldMapScene::Render()
{
	this->worldMap->Draw();
	
}

void CWorldMapScene::Update(float deltaTime)
{
	this->worldMap->Update(deltaTime);
}
void CWorldMapScene::Destroy()
{
}