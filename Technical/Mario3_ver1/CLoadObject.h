#pragma once
#include "CGlobal.h"
#include "CBaseGameObject.h"
#include "CQuadTree.h"
#include "CSingleton.h"


//Enemy
#include "CEnemyRun.h"
#include "CEnemyTurtle.h"
#include "CEnemyTurtleFly.h"
#include "CEnemyFlower.h"
#include "CEnemyFlower2.h"
//Brick
#include "CBrick.h"
#include "CStone.h"
//Effect
#include "CCoin.h"

//Bullet
#include "CBullet.h"

#define FILE_LIST_OBJECT "..\\Resources\\Object\\1-1-Object.txt"
#define FILE_LIST_OBJECT_QUADTREE "..\\Resources\\Object\\1-1-Quadtree.txt"
class CLoadObject : public CSingleton<CLoadObject>
{
	friend class CSingleton<CLoadObject>;
public:
	CLoadObject();
	~CLoadObject();


	
public:

	std::vector<CBaseGameObject*> GetListGameObjectOnScreen(){ return this->m_listGameObject; };
	void CreateObjectOnScreen();
	void Draw();
	void LoadReSourceFromFile();
	void Update(float deltaTime);
	void ChangeMap(const int&);
	void Reset(const int&);
	void Collision(float deltaTime);
public:
	std::vector<CBaseGameObject*> m_listGameObject;

	// D/s tat ca cac duong link chua file map.
	std::hash_map<int, std::string>* m_listAllGameObject;
	// hash map<stt cua man`, stt cua obj trong node, doi tuong game>

	// list quadtree
	std::hash_map<int, std::string>* m_listQuadTree;
	// <stt map, quadtree cua map>

	// List id cua doi tuong tren viewPort.
	std::vector<int> m_listIdObject;

	//Luu quad tree hien tai
	CQuadTree* m_quadTree;

	// d/s cac doi tuong cua map hien tai.
	std::hash_map<int, CBaseGameObject*> m_listObjectCurr;

	void LoadQuadTreeFromFile(const std::string&);
	void LoadGameObjectFromFile(const std::string&);
	void DeleteObjectOutScreen(float deltaTime);
	CBaseGameObject* CreateObject(int id, Vector2 pos);
	std::hash_map<int, CBaseGameObject*> LoadGameObjectInfo(const std::string&);

	// TT
	bool contains(std::vector<int> v, int x);

	int count = 0;
};

