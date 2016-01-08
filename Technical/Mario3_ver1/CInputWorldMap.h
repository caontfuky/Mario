#pragma once
#include "CInput.h"
#include "CSingleton.h"
class CInputWorldMap : public CSingleton<CInputWorldMap>
{
public:
	CInputWorldMap();
	~CInputWorldMap();

public:
	int m_keyDown;
	int m_keyUp;
	void OnKeyDown(float deltaTime);
	void OnkeyUp(float deltaTime);
	void Update(float deltaTime);
};

