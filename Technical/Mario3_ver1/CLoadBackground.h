#ifndef __CLOAD_BACK_GROUND_H__
#define __CLOAD_BACK_GROUND_H__

#pragma once
#include "CSingleton.h"
#include "CTexture.h"
#include "CSprite.h"
#include "CResourece.h"
#include "CGlobal.h"
#include "CFileUtil.h"


#define FILE_MAP "..\\Resources\\Map\\Map.txt"
class CLoadBackground :public CSingleton<CLoadBackground>
{
	friend class CSingleton<CLoadBackground>;
public:
	CLoadBackground();
	~CLoadBackground();
public:
	int** m_matrix; //Dung de luu lai ma tran
	int m_cols; //So cot ma tran
	int m_rows; //So dong ma tran
	int m_tileHeight; // Chieu rong cua tile
	int m_tileWidth; // Chieu dai cua tile
	int m_tileCols; //So luong tile tren chieu dai cua Image
	int m_tileRows; //So luong tile tren chieu rong cua Image

	CTexture* m_imageCurr; //Lay texture trong bo dem, can dung lop managertexture
	CSprite* m_drawImg; //Dung de ve anh len man hinh, can dung lop managerSprite

	bool InitMatrix();
	void LoadMatrix(std::string filePath);

public:
	void LoadBackgroundFromFile();
	void Draw();
};
#endif

