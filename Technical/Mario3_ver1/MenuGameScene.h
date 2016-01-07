#pragma once
#include"CLoadBackgroundMenu.h"
#include"ChooseItem.h"
#include"CBaseGameObject.h"
#include"CState.h"
class MenuGameScene :public CState
{
	friend class CSingleton<MenuGameScene>;
private:
	CLoadBackgroundMenu *loadBackgroundMenu;
	CChooseItem *choiseItem;
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

