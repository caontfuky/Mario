#pragma once
#include "CBaseGameObject.h"
#include "CFileUtil.h"
#include "CQuadTree.h"
struct ObjectInfo
{
	int m_idImage;
	Vector2 m_pos;
	ObjectInfo()
	{
		m_idImage = 0;
		m_pos = Vector2(0, 0);
	}
	ObjectInfo(int id, Vector2 pos)
	{
		m_idImage = id;
		m_pos = pos;
	}
};
#define FILE_LIST_OBJECT "..\\Resources\\Object\\ListObject.txt"
#define FILE_LIST_OBJECT_QUADTREE "..\\Resources\\Object\\ListObject_Quadtree.txt"
class CLoadGameObject : public CSingleton<CLoadGameObject>
{
public:
	CLoadGameObject();
	~CLoadGameObject();
public:
	std::vector<ObjectInfo> m_listObject;
	void LoadObjectFromFile(std::string filePath);

public:
	std::vector<CBaseGameObject*> m_listGameObject;

	// list quadtree
	std::hash_map<int, std::string>* m_listQuadTree;
	// <stt map, quadtree cua map>

	// List id cua doi tuong tren viewPort.
	std::vector<int> m_listIdObject;

	//Luu quad tree hien tai
	CQuadTree* m_quadTree;

	// d/s cac doi tuong cua map hien tai.
	std::hash_map<int, CBaseGameObject*> m_listObjectCurr;

public:
	std::vector<CBaseGameObject*> GetListGameObjectOnScreen(){ return this->m_listGameObject; };
	void CreateObjectOnScreen();
	void LoadQuadTreeFromFile(const std::string);
	bool contains(std::vector<int> v, int x);
	std::hash_map<int, CBaseGameObject*> LoadGameObjectInfo(const std::string&);
};

