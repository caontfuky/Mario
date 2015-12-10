#ifndef __CDRAW_OBJECT_H__
#define __CDRAW_OBJECT_H__

#include "CSingleton.h"
#include "CSprite.h"
#include "CBaseGameObject.h"
#include "CResourece.h"
#include "CCamera.h"

class CDrawObject : public CSingleton<CDrawObject>
{
	friend class CSingleton<CDrawObject>;
public:
	//Cac phuong thuc
	CDrawObject();
	~CDrawObject();
	void Draw(CBaseGameObject*);
	void Draw(CBaseGameObject*, D3DCOLOR);
private:
	//Khoi tao bien thanh vien
	CSprite* m_draw; //quan ly viec ve

};

#endif // !__CDRAW_OBJECT_H__
