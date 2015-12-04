#ifndef __CDEVICE_H__
#define __CDEVICE_H__

#include "CGlobal.h"
#include "CSingleton.h"

class CDevice : public CSingleton<CDevice>
{
	friend class CSingleton<CDevice>;
public:
	static LPDIRECT3D9	s_d3d;
	static LPDIRECT3DDEVICE9 s_d3ddv;
	static LPDIRECT3DSURFACE9 s_backBuffer;
	static LPD3DXSPRITE s_spriteHandle;
	bool InitDirect3D();
protected:
	CDevice(){};
};

#endif // !__CDEVICE_H__
