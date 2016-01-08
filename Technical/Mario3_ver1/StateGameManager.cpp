#include "StateGameManager.h"
#include "CDevice.h"


void CStateGameManager::LoadScene()
{
	menuGameScene = new MenuGameScene();
	this->gamePlayScene = new CStateGamePlay();
	gamePlayScene->Init();
	m_pCurrent = menuGameScene;
}


void CStateGameManager::Update(bool isUpdate, float deltaTime)
{
	if (this->m_pCurrent != this->m_pNext)
	{
		if (this->m_pCurrent)
		{
			this->m_pCurrent->Destroy();
			delete this->m_pCurrent;
		}
		if (this->m_pNext)
		{
			this->m_pNext->Init();
		}
		this->m_pCurrent = this->m_pNext;
	}
	if (m_pCurrent)
	{
		if (!isUpdate)
		{
			this->m_pCurrent->Update(deltaTime);
		}
		CDevice::s_d3ddv->ColorFill(CDevice::s_backBuffer, NULL, D3DCOLOR_XRGB(0, 0, 0));
		if (CDevice::s_d3ddv->BeginScene())
		{
			CDevice::s_spriteHandle->Begin(D3DXSPRITE_ALPHABLEND);
			this->m_pCurrent->Render();
			CDevice::s_spriteHandle->End();
			CDevice::s_d3ddv->EndScene();
		}
		CDevice::s_d3ddv->Present(NULL, NULL, NULL, NULL);
	}

	if (CInput::GetInstance()->IsKeyDown(DIK_Q))
	{
		isStart = true;
		m_pCurrent->isChangeState = true;
	}
	if (isStart)
	{
		timeDelay += deltaTime;
		if (timeDelay > 1.5f)
		{
			ChangeState(this->gamePlayScene);

			timeDelay = 0;
			isStart = false;
		}
	}
}

void CStateGameManager::Clear()
{
	if (this->m_pNext )
	{
		delete this->m_pNext;
	}
	if (this->m_pCurrent)
	{
		delete this->m_pCurrent;
	}

	/*if (this->menuGameScene)
	{
		delete menuGameScene;
	}
	if (this->gamePlayScene)
	{
		delete gamePlayScene;
	}*/
}

void CStateGameManager::ChangeState(CState* state)
{
	this->m_pNext = state;
}
