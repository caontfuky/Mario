#include "MenuGameScene.h"


MenuGameScene::MenuGameScene()
{
	Init();
}

void MenuGameScene::Init()
{
	this->choiseItem = new CChooseItem();
	this->loadBackgroundMenu = new CLoadBackgroundMenu();

	isChangeScene = true;
}

void MenuGameScene::Render()
{
	this->loadBackgroundMenu->Draw();
	choiseItem->Draw();
}

void MenuGameScene::Update(float deltaTime)
{
	if (isChangeState)
	{
		//MessageBox(NULL, "sd", "asd", MB_OK);
		choiseItem->EffectChangeState(deltaTime);
	}
	this->choiseItem->Update(deltaTime);
	

	this->loadBackgroundMenu->Update(deltaTime);
	
}
void MenuGameScene::Destroy()
{

}

MenuGameScene::~MenuGameScene()
{
	Destroy();
}
