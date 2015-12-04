#include "CTexture.h"
#include "CDevice.h"

CTexture::CTexture()
{
	m_d3dTexture = nullptr;
}

CTexture::~CTexture()
{
	if (m_d3dTexture)
	{
		m_d3dTexture->Release();
	}
}

bool CTexture::LoadImageFromFile(std::string filePath, D3DCOLOR color)
{
	HRESULT result; // take a value return
	//save information of source file into avaiable _infoImageT
	result = D3DXGetImageInfoFromFile(filePath.c_str(), &m_d3dInfo);
	if (result != D3D_OK)
	{
		m_d3dTexture = nullptr;
		return false;
	}
	// create a new Texture by loading bitmap image file
	result = D3DXCreateTextureFromFileEx(
		CDevice::s_d3ddv, // directx Device
		filePath.c_str(), // bitmap file
		m_d3dInfo.Width, //bitmap image width
		m_d3dInfo.Height, //bitmap image Height
		1,
		D3DPOOL_DEFAULT, // type of the surface
		D3DFMT_UNKNOWN, //surface format
		D3DPOOL_DEFAULT, // memory class for the texture
		D3DX_DEFAULT, //image filter
		D3DX_DEFAULT, //mip filter
		color, // color key for transparency
		&m_d3dInfo,//bitmap file information
		NULL, //color palette
		&m_d3dTexture //destination Texture
		);
	if (result != D3D_OK)
	{
		m_d3dTexture = NULL;
		return false;
	}
	return  true;
}

int CTexture::GetImageHeight()
{
	return this->m_d3dInfo.Height;
}

int CTexture::GetImageWidth()
{
	return this->m_d3dInfo.Width;
}