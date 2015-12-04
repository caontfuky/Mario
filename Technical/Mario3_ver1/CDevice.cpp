#include "CDevice.h"
#include "CViewWindows.h"

LPDIRECT3D9 CDevice::s_d3d = nullptr;
LPDIRECT3DDEVICE9 CDevice::s_d3ddv = nullptr;
LPDIRECT3DSURFACE9 CDevice::s_backBuffer = nullptr;
LPD3DXSPRITE CDevice::s_spriteHandle = nullptr;

bool CDevice::InitDirect3D()
{
	s_d3d = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = TRUE;

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferHeight = __SCREEN_HEIGHT;
	d3dpp.BackBufferWidth = __SCREEN_WIDTH;

	s_d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		CViewWindows::m_hwndWindow,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&s_d3ddv);

	if (!s_d3ddv)
	{
		return false;
	}

	D3DXCreateSprite(s_d3ddv, &s_spriteHandle);
	s_d3ddv->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &s_backBuffer);
	s_d3ddv->ColorFill(s_backBuffer, NULL, D3DCOLOR_XRGB(0, 0, 0));
	s_d3ddv->Present(NULL, NULL, NULL, NULL);
	return true;
}