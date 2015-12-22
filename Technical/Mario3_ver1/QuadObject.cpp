#include "QuadObject.h"


CQuadObject::CQuadObject()
{
}


CQuadObject::CQuadObject(int iD, CBaseGameObject*& obj)
{
	this->m_Id = iD;
	this->m_obj = obj;
}

CQuadObject::~CQuadObject()
{
	if (this->m_obj)
	{
		delete this->m_obj;
	}
}