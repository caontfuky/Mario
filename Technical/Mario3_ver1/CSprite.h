#ifndef __CSPRITE_H__
#define __CSPRITE_H__

#include "CGlobal.h"
#include "CTexture.h"

class CSprite
{
protected:
	//	Texture* _image;
	//LPD3DXSPRITE m_spriteHandel;
	//D3DXVECTOR3 _Pos; // possition vẽ trên màn hình
	//RECT *_RectRS; // rect Resource
	//D3DCOLOR _transcolor;

public:
	CSprite();
	~CSprite(void);
	//ve texture tai vi tri mac dinh la chinh giua
	void draw(CTexture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DCOLOR transcolor = 0xFFFFFFFF, bool isCenter = true);

	//ve texture tai vi tri mac dinh la chinh giua voi scale
	void draw(CTexture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DXVECTOR2 scale, D3DCOLOR transcolor = 0xFFFFFFFF, bool isCenter = true);

	//
	void draw(CTexture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DXVECTOR2 scale, float rotation, D3DCOLOR transcolor /* = 0xFFFFFFFF */, bool isCenter /* = true */);

	void drawS(CTexture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DXVECTOR2 scale, float rotation, D3DCOLOR transcolor /* = 0xFFFFFFFF */, bool isCenter /* = true */);

	//ve texture tai vi tri mac dinh la chinh giua.
	//va lap theo chieu ngang
	void drawFlipX(CTexture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DCOLOR transcolor = 0xFFFFFFFF, bool isCenter = true);

	//ve texture tai vi tri mac dinh la chinh giua.
	//va lap theo chieu doc
	void drawFlipY(CTexture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DCOLOR transcolor = 0xFFFFFFFF, bool isCenter = true);
	///
	///
	void drawRotation(CTexture* image, RECT *RectRS, D3DXVECTOR3 pos, float rotation, D3DCOLOR transcolor, bool isCenter);
	///
	///
	void drawScale(CTexture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DXVECTOR2 scaling, D3DCOLOR transcolor, bool isCenter);
};

#endif // !__CSPRITE_H__
