#include "CInputWorldMap.h"


CInputWorldMap::CInputWorldMap()
{
}


CInputWorldMap::~CInputWorldMap()
{
}
void CInputWorldMap::Update(float deltaTime)
{
	OnKeyDown(deltaTime);
}
void CInputWorldMap::OnKeyDown(float deltaTime)
{
	this->m_keyDown = CInput::GetInstance()->GetKeyDown();
	switch (this->m_keyDown)
	{
	case DIK_Z:
		MessageBox(NULL, "Asdsa", "asdsad", MB_OK);
		break;
	default:
		break;
	}

}
void CInputWorldMap::OnkeyUp(float deltaTime)
{
	this->m_keyUp = CInput::GetInstance()->GetKeyUp();
	switch (this->m_keyUp)
	{
	case DIK_Z:
		MessageBox(NULL, "Asdsa", "asdsad", MB_OK);
		break;
	default:
		break;
	}
}