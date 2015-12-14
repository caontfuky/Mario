#include "CCamera.h"


CCamera::CCamera()
{
	m_pos.x = 0;
	m_pos.y = 448;
	m_pos.z = 0;
	D3DXMatrixIdentity(&m_matrixTransform);
	m_matrixTransform._22 = -1;
}


CCamera::~CCamera()
{
}
void CCamera::Update(float x, float y)
{
	//m_pos.x = (this->m_pos.x < x || x == 0) ? x : m_pos.x;
	//m_pos.x = (this->m_pos.x < x || this->m_pos.x > x - 50) ? x : m_pos.x;

	if (m_pos.x < x)
	{
		m_pos.x = x;
	}
	if (m_pos.x > x - __SCREEN_WIDTH / 2)
	{
		m_pos.x = x + __SCREEN_WIDTH / 2 - 100;
		if (m_pos.x < 0)
		{
			m_pos.x = 0;
		}
	}

	m_pos.y = __SCREEN_HEIGHT;//
}

RECT*& CCamera::GetBound()
{
	RECT* rect = new RECT();
	rect->top = m_pos.y - 240;//__SCREEN_HEIGHT;
	rect->left = m_pos.x;
	rect->right = rect->left + 320;//+ __SCREEN_WIDTH;
	rect->bottom = m_pos.y;
	return rect;
}
bool CCamera::CheckCollision(CBaseGameObject *obj)
{
	if (obj->m_Pos.x < this->m_pos.x + 480)
	{
		return true;
	}
	return false;
}
Vector3 CCamera::GetPointTransform(float x, float y)
{
	m_matrixTransform._41 = -m_pos.x;
	m_matrixTransform._42 = m_pos.y;
	Vector3 posCurr(x, y, 0);
	Vector4 posResult;
	D3DXVec3Transform(&posResult, &posCurr, &m_matrixTransform);
	return Vector3(posResult.x, posResult.y, posResult.z);
}
Vector3 CCamera::GetCameraPos()
{
	return this->m_pos;
}
void CCamera::SetPos(Vector3 pos)
{
	this->m_pos = pos;
}