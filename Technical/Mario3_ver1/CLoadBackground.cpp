#include "CLoadBackground.h"
#include "CCamera.h"

CLoadBackground::CLoadBackground()
{
	this->m_imageCurr = new CTexture();
	this->m_drawImg = new CSprite();
	this->m_cols = 0;
	this->m_rows = 0;
	this->m_imageCurr->LoadImageFromFile(BACK_GROUND_1, D3DCOLOR_XRGB(255, 0, 255));
}


CLoadBackground::~CLoadBackground()
{
}
void CLoadBackground::Draw()
{
	
	RECT *rectRS = new RECT();
	D3DXVECTOR3 pos;

	for (int i = 0; i < this->m_rows; i++)
	{
		for (int j = 0; j < this->m_cols; j++)
		{
			//Ve tung tile len man hinh
			rectRS->left = (this->m_matrix[i][j] % this->m_tileCols) * this->m_tileWidth;
			rectRS->right = rectRS->left + this->m_tileWidth;
			rectRS->top = (this->m_matrix[i][j] / this->m_tileCols) * this->m_tileHeight;
			rectRS->bottom = rectRS->top + this->m_tileHeight;
			pos.x = j * this->m_tileHeight;
			pos.y = (this->m_rows - i) * this->m_tileWidth + 16;
			pos.z = 0;
			pos = CCamera::GetInstance()->GetPointTransform(pos.x, pos.y);
			this->m_drawImg->draw(this->m_imageCurr, rectRS, pos, D3DCOLOR_XRGB(255,255,225), false);
		}
	}
}
void CLoadBackground::LoadBackgroundFromFile()
{
	LoadMatrix(FILE_MAP);
	this->m_tileCols = this->m_imageCurr->GetImageWidth() / this->m_tileWidth;
	this->m_tileRows = this->m_imageCurr->GetImageHeight() / this->m_tileHeight;
}
bool CLoadBackground::InitMatrix()
{
	if (this->m_cols != 0 && this->m_rows != 0)
	{
		this->m_matrix = new int*[this->m_rows];
		for (int i = 0; i < this->m_rows; i++)
		{
			this->m_matrix[i] = new int[this->m_cols];
		}
		return true;
	}
	return false;
}
void CLoadBackground::LoadMatrix(std::string filePath)
{
	std::vector<std::string> value = CFileUtil::GetInstance()->LoadFromFile(filePath);
	std::vector<std::string> result; //Luu chuoi sau khi duoc cat
	for (int i = 0; i < value.size(); i++)
	{
		result = CFileUtil::GetInstance()->Split(value.at(i).c_str(), '\t');
		if (i == 0)
		{
			this->m_rows = std::atoi(result.at(0).c_str());
			this->m_cols = std::atoi(result.at(1).c_str());
			if (this->InitMatrix())
			{
			}
			else
			{
				MessageBox(NULL, "FAIL Load BG", "BG", MB_OK);
			}
		}
		else if (i == 1)
		{
			this->m_tileWidth = std::atoi(result.at(0).c_str());
			this->m_tileHeight = std::atoi(result.at(1).c_str());
		}
		else
		{
			for (int j = 0; j < result.size(); j++)
			{
				this->m_matrix[i - 2][j] = atoi(result.at(j).c_str());
			}
		}
	}
}