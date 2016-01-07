#pragma once
#include"CBaseGameObject.h"

class CStaticObject : public CBaseGameObject
{
public:
	virtual std::string ClassName() = 0;
	CStaticObject(void);
	~CStaticObject(void);
	virtual void Update(float deltaTime);
	virtual void Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision);
	virtual void OnCollision(float deltatime, std::vector<CBaseGameObject*>* listObjectCollision);
};

