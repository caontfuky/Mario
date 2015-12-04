#pragma once
#include <iostream>
#include "CMario.h"

using namespace GameMario;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	CViewWindows::m_hInstance = hInstance;
	CMario* game = new CMario();
	game->Run();
}