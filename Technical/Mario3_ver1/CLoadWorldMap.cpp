#include "CLoadWorldMap.h"


CLoadWorldMap::CLoadWorldMap()
{
	LoadNote(FILE_LIST_WORLDMAP);
	this->m_imageCurr = new CTexture();
	this->m_imageCurr->LoadImageFromFile(WORLD_MAP, D3DCOLOR_XRGB(255, 0, 255));
	this->m_drawImg = new CSprite();
	mario = new CMarioWorldMap();
	this->mario->SetNote(this->listNote[0]);
}


CLoadWorldMap::~CLoadWorldMap()
{
}
void CLoadWorldMap::Update(float deltaTime)
{
	this->mario->Update(deltaTime);
	this->mario->OnCollision(this->listNote);
	
}
void CLoadWorldMap::Draw()
{
	this->m_drawImg->drawScale(this->m_imageCurr, NULL, Vector3(0, 0, 0), Vector2(1, 1), D3DCOLOR_XRGB(255, 255, 225), false);
	this->mario->Draw();
	
}
int CLoadWorldMap::GetMapID()
{
	return this->mario->note.MapID;
}
void CLoadWorldMap::LoadNote(std::string path)
{
	std::vector<std::string> value = CFileUtil::GetInstance()->LoadFromFile(path);
	std::vector<std::string> result; //Luu chuoi sau khi duoc cat
	for (int i = 1; i < value.size(); i++)
	{
		result = CFileUtil::GetInstance()->Split(value.at(i).c_str(), '\t');

		int stt = std::atoi(result.at(0).c_str());
		int id = std::atoi(result.at(1).c_str());
		float posX = std::atoi(result.at(2).c_str());
		float posY = std::atoi(result.at(3).c_str());
		float width = std::atoi(result.at(4).c_str());
		float height = std::atoi(result.at(5).c_str());

		bool t = std::atoi(result.at(6).c_str());
		bool d = std::atoi(result.at(7).c_str());
		bool l = std::atoi(result.at(8).c_str());
		bool r = std::atoi(result.at(9).c_str());

		int mapId = std::atoi(result.at(10).c_str());

		Note n = Note(stt, id, Vector2(posX, posY), width, height, t, l, d, r, mapId);

		this->listNote.push_back(n);
	}
}