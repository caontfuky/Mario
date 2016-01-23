#include "StateGameManager.h"
#include "CDevice.h"
#include"CManageAudio.h"

void CStateGameManager::LoadScene()
{
	

	menuGameScene = new MenuGameScene();
	this->worldMapScene = new CWorldMapScene();
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

	
	if (CInput::GetInstance()->IsKeyDown(DIK_RETURN))
	{
		if (isStart == false)
		{
			ManageAudio::GetInstance()->playSound(TypeAudio::AUDIO_MARIO_COLLISION_BRICK);
		}
		isStart = true;
		m_pCurrent->isChangeState = true;
		
	}

	if (isStart)
	{
		timeDelay += deltaTime;
		if (timeDelay > 1.0f)
		{
			if (this->m_pCurrent != this->worldMapScene && this->m_pCurrent != this->gamePlayScene)
			{
				ManageAudio::GetInstance()->playSound(TypeAudio::AUDIO_WORLD_MAP);
				ManageAudio::GetInstance()->stopSound(TypeAudio::AUDIO_BACKGROUND_STATE_1);
				ChangeState(this->worldMapScene);
			}
				

			timeDelay = 0;
			isStart = false;
		}
	}
	
	
	if (this->m_pCurrent == this->worldMapScene)
	{
		gamePlayScene->m_mapId = this->worldMapScene->worldMap->mario->note.MapID;

		if (CInput::GetInstance()->IsKeyDown(DIK_RETURN) && gamePlayScene->m_mapId != -1)
		{
			ChangeState(gamePlayScene);
			ManageAudio::GetInstance()->stopSound(TypeAudio::AUDIO_WORLD_MAP);
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
