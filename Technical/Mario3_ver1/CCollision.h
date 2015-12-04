#ifndef __CCOLLISION_H__
#define __CCOLLISION_H__

#define NOMINMAX

#include "CCollision.h"
#include "CGlobal.h"
#include "CBaseGameObject.h"
#include "CSingleton.h"

class CCollision : public CSingleton<CCollision>
{
	friend class CSingleton<CCollision>;
public:
	float SweptAABB(Box first, Box second, float& normalx, float& normaly, float deltaTime);
	Box GetSweptBroadphaseBox(Box box, float deltaTime);
	bool AABBCheck(Box b1, Box b2, float& moveX, float& moveY, float& normalX, float& normalY);
	bool AABBCheck(Box b1, Box b2);
	float Collision(CBaseGameObject* ObjectA, CBaseGameObject* ObjectB, float& normalx, float& normaly, float& moveX, float& moveY, float deltaTime);
	bool Collision(CBaseGameObject* ObjectA, CBaseGameObject* ObjectB);
	bool Collision(CBaseGameObject* ObjectA, Box box);
	float Collision(CBaseGameObject* ObjectA, Box box, float& normalx, float& normaly, float& moveX, float& moveY, float deltaTime);

	bool Collision(CBaseGameObject* ObjectA, std::vector<Box> listBox);
	CCollision();
	~CCollision();
private:

};

#endif // !__CCOLLISION_H__