#pragma once
#include "QuadObject.h"

#include "CGlobal.h"

class CQuadNode
{
public:
	CQuadNode();
	CQuadNode(int iD, float posX, float posY, float height, float width);
	~CQuadNode();
	int GetID(){ return this->m_ID; }
	void SetID(int iD){ this->m_ID = iD; }
	void SetPosX(float posX){ this->m_posX = posX; }
	void SetPosY(float posY){ this->m_posY = posY; }
	float GetPosX(){ return this->m_posX; };
	float GetPosY(){ return this->m_posY; };
	void SetWidth(float width){ this->m_width = width; }
	void SetHeight(float height){ this->m_height = height; }
	float GetWidth(){ return this->m_width; };
	float GetHeight(){ return this->m_height; };
	void SetNodeTL(CQuadNode*& node){ this->m_nodeTL = node; };
	void SetNodeTR(CQuadNode*& node){ this->m_nodeTR = node; };
	void SetNodeBL(CQuadNode*& node){ this->m_nodeBL = node; };
	void SetNodeBR(CQuadNode*& node){ this->m_nodeBR = node; };
	CQuadNode*& GetNodeTL(){ return this->m_nodeTL; };
	CQuadNode*& GetNodeTR(){ return this->m_nodeTR; };
	CQuadNode*& GetNodeBL(){ return this->m_nodeBL; };
	CQuadNode*& GetNodeBR(){ return this->m_nodeBR; };
	void SetListObject(std::vector<int>*& list){ this->m_listObject = list; };
	std::vector<int>*& GetListObject(){ return this->m_listObject; };
	RECT* GetBound();
	void ClipObject(CQuadObject*&);
	void DeleteObjectFromQuadNode(CQuadObject*&);
	void Clear();
private:
	//ID node
	int m_ID;
	//Kich thuoc cua node
	float m_posX;
	float m_posY;
	float m_height;
	float m_width;
	CQuadNode* m_nodeTL;
	CQuadNode* m_nodeTR;
	CQuadNode* m_nodeBL;
	CQuadNode* m_nodeBR;
	//List luu giu doi tuong cua quadtree
	std::vector<int>* m_listObject;
	//const int MIN_SIZE_OF_NODE = 400;
public:
	//Dung de check giao nhau giua hai node
	bool IntersectRectRS(RECT*, RECT*);
};

