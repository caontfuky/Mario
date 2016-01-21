#include "CMario.h"
#include "StateGameManager.h"
#include "CStateGamePlay.h"	
#include "CDevice.h"
#include "CInput.h"
#include "CManageAudio.h"

CMario::CMario()
{

}

void CMario::Init()
{
	CViewWindows::GetInstance()->InitClienWindow();
	CDevice::GetInstance()->InitDirect3D();
	CInput::GetInstance()->InitInput(CViewWindows::m_hInstance);
	CInput::GetInstance()->InitKeyboard(CViewWindows::m_hwndWindow);

	CStateGameManager::GetInstance()->LoadScene();
	CStateGameManager::GetInstance()->ChangeState(new MenuGameScene());


	//Audio
	ManageAudio::GetInstance()->init_DirectSound(CViewWindows::m_hwndWindow);
	ManageAudio::GetInstance()->readFileAudio();
}

void CMario::Destroy()
{

}

void CMario::ProcessInput()
{
	CInput::GetInstance()->ProcessKeyboard();
	CInput::GetInstance()->Update();
}