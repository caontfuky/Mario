#include "CLoadGameObject.h"


CLoadGameObject::CLoadGameObject()
{
	this->m_listGameObject = std::vector<CBaseGameObject*>();
	this->m_listQuadTree = new std::hash_map<int, std::string>();	
	this->m_quadTree = new CQuadTree();
}


CLoadGameObject::~CLoadGameObject()
{
}
void CLoadGameObject::LoadObjectFromFile(std::string filePath)
{
	std::vector<std::string> value = CFileUtil::GetInstance()->LoadFromFile(filePath);
	std::vector<std::string> result; //Luu chuoi sau khi duoc cat
	for (int i = 0; i < value.size(); i++)
	{
		result = CFileUtil::GetInstance()->Split(value.at(i).c_str(), '\t');

		int stt = std::atoi(result.at(0).c_str());
		int id = std::atoi(result.at(1).c_str());
		float  posX = std::atoi(result.at(2).c_str());
		float posY = std::atoi(result.at(3).c_str());
		float width = std::atoi(result.at(4).c_str());
		float height = std::atoi(result.at(5).c_str());

		Vector2 pos = Vector2(posX, posY);
		ObjectInfo box = ObjectInfo(id, pos);

		this->m_listObject.push_back(box);
	}
}
void CLoadGameObject::LoadQuadTreeFromFile(std::string filePath)
{
	this->m_quadTree->ReBuildQuadTree(filePath);
}
