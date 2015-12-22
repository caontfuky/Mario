#pragma once
#include "CBaseGameObject.h"
class CQuadObject
{
public:
	int GetID(){ return m_Id; };
	CBaseGameObject* GetGameObject(){ return this->m_obj; };
	CQuadObject();
	CQuadObject(int iD, CBaseGameObject*&);
	~CQuadObject();
protected:
	int m_Id;
	CBaseGameObject* m_obj;
};

