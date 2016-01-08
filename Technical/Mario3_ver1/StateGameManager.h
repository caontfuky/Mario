#ifndef __CSTATEMANAGEMENT_H__
#define __CSTATEMANAGEMENT_H__

#include "CSingleton.h"
#include "CState.h"
#include"MenuGameScene.h"
#include"CStateGamePlay.h"
#include "CWorldMapScene.h"

enum StateScene
{
	MENU_SCENE = 1,
	GAME_PLAY_SCENE = 2,
	GAMEOVERSCENE = 3
};

class CStateGameManager : public CSingleton<CStateGameManager>
{
	friend class CSingleton<CStateGameManager>;
private:
	float timeDelay;
public:
	//static CStateManagement* m_instante;
	//static CStateManagement* GetInstance();
	StateScene currentScene;
	void LoadScene();
	void Update(bool isUpdate, float deltaTime);
	void ChangeState(CState*);

	void Clear();
public:
	MenuGameScene *menuGameScene;
	CWorldMapScene *worldMapScene;
	CStateGamePlay *gamePlayScene;
	bool isStart;
protected:
	CStateGameManager() : m_pNext(0), m_pCurrent(0){}
protected:
	CState* m_pNext;
	CState* m_pCurrent;
};
#endif // !__CSTATEMANAGEMENT_H__
