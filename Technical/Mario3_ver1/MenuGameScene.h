#pragma once
#include"CLoadBackgroundMenu.h"
#include"ChooseItem.h"
#include"CBaseGameObject.h"
#include"CState.h"

class MenuGameScene :public CState
{
public:
	CLoadBackgroundMenu *loadBackgroundMenu;
	CChooseItem *choiseItem;
	bool isChangeScene;
public:
	//void Update(float deltaTime);//ham Update chinh cua game
	//void Init();
	//void Draw();
	void Init();
	void Update(float deltaTime);
	void Render();
	void Destroy();
	MenuGameScene();
	~MenuGameScene();
};

