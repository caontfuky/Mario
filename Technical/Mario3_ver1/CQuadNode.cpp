#include "CQuadNode.h"
#include <Windows.h>

CQuadNode::CQuadNode()
{
	this->m_ID = 0;
	this->m_posX = 0.0f;
	this->m_posY = 0.0f;
	this->m_height = 0.0f;
	this->m_width = 0.0f;
	this->m_listObject = new std::vector<int>();
	this->m_nodeTL = nullptr;
	this->m_nodeTR = nullptr;
	this->m_nodeBL = nullptr;
	this->m_nodeBR = nullptr;
}


CQuadNode::CQuadNode(int iD, float posX, float posY, float height, float width)
{
	this->m_ID = iD;
	this->m_posX = posX;
	this->m_posY = posY;
	this->m_height = height;
	this->m_width = width;
	this->m_listObject = new std::vector<int>();
	this->m_nodeTL = nullptr;
	this->m_nodeTR = nullptr;
	this->m_nodeBL = nullptr;
	this->m_nodeBR = nullptr;
}
CQuadNode::~CQuadNode()
{
	if (m_listObject)
	{
		m_listObject->clear();
		delete m_listObject;
	}
	if (this->m_nodeTL)
	{
		this->m_nodeTL->~CQuadNode();
		this->m_nodeTR->~CQuadNode();
		this->m_nodeBL->~CQuadNode();
		this->m_nodeBR->~CQuadNode();
	}
	else
	{
		delete this;
	}

}

RECT* CQuadNode::GetBound()
{
	RECT* rect = new RECT();
	rect->top = this->m_posY;
	rect->left = this->m_posX;
	rect->bottom = rect->top + this->m_height;
	rect->right = rect->left + this->m_width;
	return rect;
}

// xen' doi tuong, voi node.
void CQuadNode::ClipObject(CQuadObject*& obj)
{
	CBaseGameObject* gameObj = obj->GetGameObject();
	if (gameObj)
	{
		if (IntersectRectRS(gameObj->GetBound(), this->GetBound()))
		{
			if (this->m_nodeTL)
			{
				this->m_nodeTL->ClipObject(obj);
				this->m_nodeTR->ClipObject(obj);
				this->m_nodeBL->ClipObject(obj);
				this->m_nodeBR->ClipObject(obj);
			}
			else
			{
				// TT
				// kiem tra co phai la nut la hay k
				//if(this->GetHeight > )
				//{}
				this->m_listObject->push_back(obj->GetID());
			}
		}
	}
}

//Xoa doi tuong ra khoi node
void CQuadNode::DeleteObjectFromQuadNode(CQuadObject*& obj)
{
	if (obj)
	{
		CBaseGameObject* gameObj = obj->GetGameObject();
		if (gameObj)
		{
			if (IntersectRectRS(gameObj->GetBound(), this->GetBound()))
			{
				if (this->m_nodeTL)
				{
					this->m_nodeTL->DeleteObjectFromQuadNode(obj);
					this->m_nodeTR->DeleteObjectFromQuadNode(obj);
					this->m_nodeBL->DeleteObjectFromQuadNode(obj);
					this->m_nodeBR->DeleteObjectFromQuadNode(obj);
				}
				else
				{
					if (this->m_listObject)
					{
						int size = this->m_listObject->size();
						for (int i = 0; i < this->m_listObject->size(); ++i)
						{
							int iD = this->m_listObject->at(i);
							if (this->m_listObject->at(i))
							{
								if (iD == obj->GetID())
								{
									this->m_listObject->erase(this->m_listObject->begin() + i);
								}
							}
						}
					}
				}
			}
		}
	}
}
//Dung de check giao nhau giua hai node
bool CQuadNode::IntersectRectRS(RECT* rectFirst, RECT* rectSecond)
{
	LPRECT result = new RECT();
	IntersectRect(result, rectFirst, rectSecond);
	if (result->left != 0 || result->right != 0 || result->bottom != 0 || result->top != 0)
	{
		return true;
	}
	return false;
}

void CQuadNode::Clear()
{
	if (this->m_nodeTL)
		this->m_nodeTL->Clear();
	if (this->m_nodeTR)
		this->m_nodeTR->Clear();
	if (this->m_nodeBL)
		this->m_nodeBL->Clear();
	if (this->m_nodeBR)
		this->m_nodeBR->Clear();
	if (!this->m_nodeTL&&
		!this->m_nodeTR &&
		!this->m_nodeBL &&
		!this->m_nodeBR)
	{
		//delete this;
		return;
	}
}

