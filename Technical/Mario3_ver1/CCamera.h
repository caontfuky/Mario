#ifndef __CCAMERA_H__
#define __CCAMERA_H__

#include "CGlobal.h"
#include "CSingleton.h"
#include "CBaseGameObject.h"
class CCamera : public CSingleton<CCamera>
{
public:
	CCamera();
	~CCamera();
public:
	void Update(float x, float y); //Update vi tri cua camera
	RECT*& GetBound();
	Vector3 GetPointTransform(float x, float y); // Tra ve vi tri da transform
	Vector3 m_pos;
	Matrix m_matrixTransform;
public:
	Vector3 GetCameraPos();
	void SetPos(Vector3);
	bool CheckCollision(CBaseGameObject *obj);
};
#endif

