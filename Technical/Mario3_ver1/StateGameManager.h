#ifndef __CSTATEMANAGEMENT_H__
#define __CSTATEMANAGEMENT_H__

#include "CSingleton.h"
#include "CState.h"
#include"MenuGameScene.h"
#include"CStateGamePlay.h"

enum StateScene
{
	MENU_SCENE = 1,
	GAME_PLAY_SCENE = 2,
	GAMEOVERSCENE = 3
};


class CStateGameManager : public CSingleton<CStateGameManager>
{
	friend class CSingleton<CStateGameManager>;
public:
	//static CStateManagement* m_instante;
	//static CStateManagement* GetInstance();
	StateScene currentScene;
	void LoadScene();
	void Update(bool isUpdate, float deltaTime);

	void ChangeState(CState*);
public:
	MenuGameScene *menuGameScene;
	CStateGamePlay *gamePlayScene;
protected:
	CStateGameManager() : m_pNext(0), m_pCurrent(0){}
protected:

	CState* m_pNext;
	CState* m_pCurrent;
};
#endif // !__CSTATEMANAGEMENT_H__
