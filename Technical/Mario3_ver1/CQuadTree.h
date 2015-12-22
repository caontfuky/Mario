#pragma once

#include "CQuadNode.h"
class CQuadTree
{
public:
	CQuadTree();
	~CQuadTree();
	void ReBuildQuadTree(std::vector<CQuadObject*>& listQuadObj);
	void ReBuildQuadTree(const std::string& file);
	void BuildQuadTree();
	void SetMaxID(int maxID){ this->m_maxID = maxID; };
	void AddNode(CQuadNode*&, CQuadNode*&);
	CQuadNode*& GetRoot(){ return this->m_nodeRoot; };
	CQuadNode*& SearchNode(int iDNode, CQuadNode*&);
	void GetListObjectOnScreen(RECT*, CQuadNode*&, std::vector<int>&);
	std::vector<int> m_listIdObject();
	void AddGameObjectToQuadTree(CBaseGameObject*&);
	void AddGameObjectToQuadTree(CQuadObject* quadObj);
	void DeleteGameObjectFromQuadTree(CQuadObject*);
	void Clear();
protected:
	CQuadNode* m_nodeRoot;
	//Doi tuong co id lon nhat trong quadtree
	int m_maxID;
private:
	bool Contains(int ID, const std::vector<int>& list);
};

