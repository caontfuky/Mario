#include "CAnimation.h"

CAnimation::CAnimation()
{

}

CAnimation::~CAnimation()
{

}

void CAnimation::ChangeFrame(float deltaTime)
{
	this->m_currentTime += deltaTime;
	if (this->m_currentTime > this->m_elapseTimeChangeFrame)
	{
		//this->m_currentTime = 0.0f;
		this->m_currentFrame += this->m_increase;
		if (this->m_currentFrame > this->m_endFrame || this->m_currentFrame < this->m_startFrame)
		{
			this->m_currentFrame = this->m_startFrame;
		}
		this->m_currentTime -= this->m_elapseTimeChangeFrame;
	}
}

RECT*& CAnimation::UpdateRectResource(int rsHeight, int rsWidth)
{
	RECT* rectRS = new RECT();
	int x, y;
	x = (this->m_currentFrame % this->m_column) * rsWidth;
	y = (this->m_currentFrame / this->m_column) * rsHeight;
	//cập nhật lại vị trí của Rect Resource
	rectRS->left = x;
	rectRS->right = x + rsWidth;
	rectRS->top = y;
	rectRS->bottom = y + rsHeight;
	return rectRS;
}