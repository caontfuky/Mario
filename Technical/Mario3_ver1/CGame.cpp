#include "CGame.h"
#include <stdlib.h>
#include <iostream>
#include "CGlobal.h"
#include "StateGameManager.h"

namespace GameMario
{
	CGame::CGame() : m_isAlived(true), m_isPaused(false) {}

	void CGame::Run()
	{
		MSG msg;
		int done = 0;
		//DWORD frameStart = GetTickCount();
		float tickPerFrame = 1.0f / __FRAME_RATE;
		__int64 cntsPerSec = 0;
		QueryPerformanceFrequency((LARGE_INTEGER*)&cntsPerSec);
		float secsPerCnt = 1.0f / (float)cntsPerSec;
		__int64 prevTimeStamp = 0;
		QueryPerformanceCounter((LARGE_INTEGER*)&prevTimeStamp);
		this->Init(); //Khoi tao game
		while (!done)
		{
			if (!this->m_isAlived) //Kiem tra game con hoat dong
			{
				return;
			}
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				if (msg.message == WM_QUIT) done = 1;

				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

			//DWORD now = GetTickCount();//Xem lai sau
			//DWORD deltaTime = (now - frameStart); 
			__int64 currTimeStamp = 0;
			QueryPerformanceCounter((LARGE_INTEGER*)&currTimeStamp);
			float deltaTime = (currTimeStamp - prevTimeStamp)*secsPerCnt;
			if (deltaTime >= tickPerFrame)
			{
				//frameStart = now;
				prevTimeStamp = currTimeStamp;
				//float delta_time = (float)deltaTime / 1000;
				if (deltaTime > tickPerFrame)
					deltaTime = tickPerFrame;
				this->ProcessInput();
				if (this->m_isPaused)
				{
					CStateGameManager::GetInstance()->Update(true, deltaTime);
				}
				else
				{
					CStateGameManager::GetInstance()->Update(false, deltaTime);
				}
			}
		}
		//while (this->m_isAlived)
		//{
		//	if(this->m_isPaused)
		//	{
		//		CStateManagement::GetInstance()->Update(true);
		//	}
		//	else
		//	{
		//		CStateManagement::GetInstance()->Update(false);
		//	}
		//	Sleep(80);
		//}
		Destroy();
	}

	void CGame::Destroy()
	{
		this->m_isAlived = false;
	}

	void CGame::Pause()
	{
		this->m_isPaused = true;
	}

	void CGame::Resume()
	{
		this->m_isPaused = false;
	}

	void CGame::Exit()
	{

	}

	void CGame::ProcessInput()
	{

	}
}