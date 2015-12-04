#ifndef __CGAME_MARIO_H__
#define __CGAME_MARIO_H__

#pragma once
#include "CGame.h"
#include "CViewWindows.h"

using namespace GameMario;

class CMario: public CGame
{
public:
	CMario();
	virtual ~CMario(){};
protected:
	virtual void Init();
	virtual void ProcessInput();
	virtual void Destroy();
};
#endif // !__CGAME_MARIO_H__
