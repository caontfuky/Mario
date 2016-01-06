#include "CLoadObject.h"
#include "CFileUtil.h"
#include "CCamera.h"
#include "CDrawObject.h"


CLoadObject::CLoadObject()
{
	this->m_listGameObject = std::vector<CBaseGameObject*>();
	this->m_listQuadTree = new std::hash_map<int, std::string>();
	this->m_listAllGameObject = new std::hash_map<int, std::string>();
	this->m_quadTree = new CQuadTree();

}


CLoadObject::~CLoadObject()
{
}
void CLoadObject::LoadReSourceFromFile()
{
	this->m_quadTree->ReBuildQuadTree(FILE_LIST_OBJECT_QUADTREE);
	this->m_listObjectCurr = this->LoadGameObjectInfo(FILE_LIST_OBJECT);
	//this->CreateObjectOnScreen();
	//LoadQuadTreeFromFile(__QuadTree_Path__);
	//LoadGameObjectFromFile(__Map_Path__);
}
void CLoadObject::LoadQuadTreeFromFile(const std::string& filePath)
{
	int mapID;
	std::string pathItem;
	typedef pair<int, std::string> Pair;
	std::vector<std::string> result = CFileUtil::GetInstance()->LoadFromFile(filePath); //Load tat ca cac duong dan tu nguon
	std::vector<std::string> item; //Lay tung item trong result
	for (int i = 0; i < result.size(); i++)
	{
		item = CFileUtil::GetInstance()->Split(result.at(i).c_str(), ',');
		mapID = atoi(item.at(0).c_str());
		pathItem = item.at(1).c_str();
		//Tao CTexture
		//this->m_quadTree->ReBuildQuadTree(pathItem);
		this->m_listQuadTree->insert(Pair(mapID, pathItem));
	}
}
//Xen trong quadtree va khoi tao doi tuong
void CLoadObject::CreateObjectOnScreen()
{
	// danh sach tam.
	std::vector<int> m_oldListIdObject;
	m_oldListIdObject.swap(this->m_listIdObject);
	this->m_listIdObject.clear();

	if (this->m_quadTree)
	{
		// Lay ra danh sach id cua doi tuong dinh voi viewPort.
		this->m_quadTree->GetListObjectOnScreen(CCamera::GetInstance()->GetBound(),
			this->m_quadTree->GetRoot(),
			m_listIdObject);

		if (m_listIdObject.size() != 0)
		{
			// Duyet qua tung phan tu cua d/s cac doi tuong tren man hinh..
			// Neu doi tuong trong ds moi nay
			// - Co trong moi + co trong cu => thuc hien update
			// - Moi co + cu k co => thuc hien ve doi tuong do ra
			// - Moi k co + cu co => xoa doi tuong ra khoi d/s can ve

			// xoa dt khoi d/s
			vector<CBaseGameObject*>::iterator it;

			// Duyet moi trong cu
			for (int j = 0; j < m_oldListIdObject.size(); j++)
			{
				// List moi co, ma cu k co
				// Thuc hien xoa doi tuong khoi node.
				if (!contains(m_listIdObject, m_oldListIdObject.at(j)))
				{
					for (it = m_listGameObject.begin(); it != m_listGameObject.end();)
					{
 						if (*it == this->m_listObjectCurr.find(m_oldListIdObject.at(j))->second)
						{
							//Xoa doi tuong cu ra khoi danh sach.
							it = this->m_listGameObject.erase(it);
						}
						else
							++it;
					}
				}
			}

			// Duyet cu trong moi
			for (int i = 0; i < m_listIdObject.size(); i++)
			{
				// m_listIdObject la ds moi
				// m_oldListIdObject la ds cu.

				// Co trong moi nhung k ton tai trong cu
				if (!contains(m_oldListIdObject, m_listIdObject.at(i)))
				{
					//NO bo cho nay sau khi goi change map no trung doi tuong
					// Them doi tuong vao d/s
					
					if (this->m_listObjectCurr.find(m_listIdObject.at(i)) != this->m_listObjectCurr.end())
					{
						this->m_listGameObject.push_back(this->m_listObjectCurr.find(m_listIdObject.at(i))->second);
					}
					else
					{
						int count = 0;
					}
					
					
				}
				
			}
		}
	}

}
// tt
bool CLoadObject::contains(std::vector<int> v, int x)
{
	if (std::find(v.begin(), v.end(), x) != v.end()) {
		/* v contains x */
		return true;
	}
	else {
		/* v does not contain x */
		return false;
	}
}
CBaseGameObject* CLoadObject::CreateObject(int id, Vector2 pos)
{
	
	switch (id)
	{
		//case 12:
		//{
		//		   //return CFactoryDynamicObject::GetInstance()->CreateObject(info);
		//		   break;
		//}
		//case 11: case 13: case 14: case 15: case 16: case 17:
		//{
		//			 //return CFactoryStaticObject::GetInstance()->CreateObject(info);
		//			 break;
		//}
	case 601://Cuc gach an tien binh thuong
		return new CBrick(pos);
		break;
	case 602://Brick Item
		return new CBrick(pos, 2);
		break;
	case 603://Coin
		return new CCoin(pos, true);
		break;
	case 604://Item
		return new CBrick(pos);
		break;

		//Enemy

		
	case 201://Nam' Di chuyen qua lai
		return new CEnemyRun(pos, LEVEL::LEVEL_0);
		break;
		
	case 202://Nam Bay
		return new CEnemyRun(Vector2(pos), LEVEL::LEVEL_1);
		break;
		
	case 203://Rua mau do di chuyen qua lai		
		return new CEnemyTurtle(pos, 0);
		break;

	case 204://Hoa mau do ban dan
		return new CEnemyFlower(pos);
		break;

	case 205://Rua mau xanh biet bay
		return new CEnemyTurtleFly(pos);
		break;

	case 206://Hoa mau xanh can
		return new CEnemyFlower2(pos);
		break;

	case 207://Hoa mau xanh ban
		return new CEnemyFlower(pos, 2);
		break;

	case 208://Rua mau xanh di bo
		return new CEnemyTurtleFly(pos,ENEMY_STATUS::ENEMY_MOVE);
		break;

	default:
		break;
	}
	
}
void CLoadObject::DeleteObjectOutScreen(float deltaTime)
{

}
void CLoadObject::Draw()
{	
	
	for (std::vector<CBaseGameObject*>::iterator it = this->m_listGameObject.begin();
		it != this->m_listGameObject.end();
		++it)
		{
			CBaseGameObject* gameObj = *it;		
				CDrawObject::GetInstance()->Draw(gameObj);
		}
}
void CLoadObject::Collision(float deltaTime)
{

	for (std::vector<CBaseGameObject*>::iterator it = this->m_listGameObject.begin();
		it != this->m_listGameObject.end();
		++it)
	{
		CBaseGameObject* gameObj = *it;
		if (gameObj != NULL)
		{
			gameObj->OnCollision(deltaTime, CBoxGround::GetInstance()->listGround);
			gameObj->OnCollision(deltaTime, this->m_listGameObject);			
		}
	}
}
void CLoadObject::Update(float deltaTime)
{
	this->CreateObjectOnScreen();
	
	for (std::vector<CBaseGameObject*>::iterator it = this->m_listGameObject.begin();
		it != this->m_listGameObject.end();
		)
	{
		CBaseGameObject* gameObj = *it;
		
		if (gameObj != NULL && gameObj->isRemove == false)
		{
			gameObj->Update(deltaTime);			
		}
		if (gameObj->isRemove)
		{
			it = this->m_listGameObject.erase(it);
		}
		else
		{
			it++;
		}
		
	}
	Collision(deltaTime);//enemy va cham voi Ground
}
void CLoadObject::LoadGameObjectFromFile(const std::string& filePath)
{
	this->m_listAllGameObject->clear();
	//
	int mapID;
	std::string pathItem;
	typedef pair<int, std::string> Pair;
	std::vector<std::string> result = CFileUtil::GetInstance()->LoadFromFile(filePath); //Load tat ca cac duong dan tu nguon
	std::vector<std::string> item; //Lay tung item trong result
	std::vector<std::string> data; //Luu du lieu lay len tu mot file
	for (int i = 0; i < result.size(); i++)
	{
		item = CFileUtil::GetInstance()->Split(result.at(i).c_str(), ',');
		mapID = atoi(item.at(0).c_str());
		pathItem = item.at(1).c_str();
		//Load thong tin info
		//std::hash_map<int, CGameObject*> listInfo = this->LoadGameObjectInfo(pathItem);
		this->m_listAllGameObject->insert(Pair(mapID, pathItem));
	}
}
std::hash_map<int, CBaseGameObject*> CLoadObject::LoadGameObjectInfo(const std::string& filePath)
{
	std::hash_map<int, CBaseGameObject*> listInfo;
	std::vector<std::string> data = CFileUtil::GetInstance()->LoadFromFile(filePath);
	std::vector<std::string> item;
	typedef pair<int, CBaseGameObject*> Pair;
	if (!data.empty())
	{
		int size = data.size();
		int iDObjectInMap;
		for (int i = 0; i < size; i++)
		{
			CBaseGameObject* gameObj;
			std::vector<int> info;
			item = CFileUtil::GetInstance()->Split(data.at(i).c_str(), '\t');
			if (!item.empty())
			{
				iDObjectInMap = atoi(item.at(0).c_str());
				int idItem = atoi(item.at(1).c_str());
				float x = atoi(item.at(2).c_str());
				float y = atoi(item.at(3).c_str());
				Vector2 pos = Vector2(x, y);
				/*int sizeItem = item.size();
				int temp;
				iDObjectInMap = atoi(item.at(0).c_str());
				for (int j = 1; j < sizeItem; j++)
				{
					info.push_back(atoi(item.at(j).c_str()));
				}*/
				gameObj = this->CreateObject(idItem, pos);
				listInfo.insert(Pair(iDObjectInMap, gameObj));
			}

		}
	}
	return listInfo;
}
void CLoadObject::ChangeMap(const int& idMap)
{
	//Xoa nhung doi tuong con trong viewport map truoc
	this->m_listIdObject.clear();
	//
	if (this->m_listQuadTree)
	{
		this->m_quadTree->Clear();
		this->m_quadTree = nullptr;
		this->m_quadTree = new CQuadTree();
		std::hash_map<int, std::string>::iterator it = this->m_listQuadTree->find(idMap);
		if (it != this->m_listQuadTree->end())
		{
			this->m_quadTree->ReBuildQuadTree(it->second);
		}
		else
		{
			throw;
		}
	}
	if (this->m_listAllGameObject)
	{
		this->m_listObjectCurr.clear();
		std::hash_map<int, std::string>::iterator it = this->m_listAllGameObject->find(idMap);
		if (it != this->m_listAllGameObject->end())
		{
			this->m_listObjectCurr = this->LoadGameObjectInfo(it->second);
		}
		else
		{
			throw;
		}
	}
}
void CLoadObject::Reset(const int& idMap)
{
	//Lam rong danh sach doi tuong trong listGameObject- cac doi tuong co tren man hinh
	/*if (this->m_listGameObject)
		m_listGameObject->clear();*/
	//
	if (this->m_listAllGameObject)
	{
		this->m_listObjectCurr.clear();
		std::hash_map<int, std::string>::iterator it = this->m_listAllGameObject->find(idMap);
		if (it != this->m_listAllGameObject->end())
		{
			this->m_listObjectCurr = this->LoadGameObjectInfo(it->second);
		}
		else
		{
			throw;
		}
	}
	//Load lai danh sach cac doi tuong tren man hinh
	// TT
	this->CreateObjectOnScreen();
	int x = 0;
}
