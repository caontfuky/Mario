#pragma once
#include "CTexture.h"
#include "CSprite.h"
#include "CSingleton.h"
#include "CInput.h"
#include "CResourece.h"
#include "CSingleton.h"
#include "CMarioWorldMap.h"
#include "CFileUtil.h"

#define FILE_LIST_WORLDMAP "..\\Resources\\WorldMap\\WorldMap.txt"
class CLoadWorldMap : public CSingleton<CLoadWorldMap>
{
public:
	CLoadWorldMap();
	~CLoadWorldMap();
public:
	CMarioWorldMap *mario;
	CTexture* m_imageCurr; //Lay texture trong bo dem, can dung lop managertexture
	CSprite* m_drawImg; //Dung de ve anh len man hinh, can dung lop managerSprite

	void Draw();
	void LoadNote(std::string path);
	void Update(float deltaTime);
public:
	Note note;
	std::vector<Note> listNote;
};

