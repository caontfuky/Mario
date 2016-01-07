#ifndef __CLOAD_BACK_GROUND_MENU_H__
#define __CLOAD_BACK_GROUND_MENU_H__

#pragma once
#include "CSingleton.h"
#include "CTexture.h"
#include "CSprite.h"
#include "CResourece.h"
#include "CGlobal.h"
#include "CFileUtil.h"
#include "CQuadTree.h"
#include "ChooseItem.h"

#define FILE_MAP_MENU "..\\Resources\\Map\\Quadtree\\bg_menu_1.txt"

class CLoadBackgroundMenu :public CSingleton<CLoadBackgroundMenu>
{
	friend class CSingleton<CLoadBackgroundMenu>;
public:
	CLoadBackgroundMenu();
	~CLoadBackgroundMenu();

	CChooseItem *m_chooseItem ;
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
	CQuadTree* m_quadTree; // Luu quadtree hien tai

	std::hash_map<int, std::string>* m_listQuadTree; //Su dung de luu danh sach quadtree
	std::hash_map<int, std::string>* m_listBackGroundImage; //Su dung de luu tat ca cac tileMap Image
	std::hash_map<int, std::string>* m_listBackGroundMatrix; //Su dung de luu tat ca cac tileMap Matrix
	void LoadAllTextureFromFile(std::string);
	void LoadAllQuadTreeFromFile(std::string);
	void LoadAllMatrixFromFile(std::string);

	bool InitMatrix();
	void LoadMatrix(std::string filePath);
	void DeleteMatrix();
	void Clear(); //Xoa noi dug hien tai

	void Update(float deltaTime);
public:
	void LoadBackgroundFromFile();
	void Draw();

};
#endif

