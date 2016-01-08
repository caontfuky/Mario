#include "CStateGamePlay.h"
#include "CDrawObject.h"
#include "CBoxGround.h"
CStateGamePlay::CStateGamePlay()
{
	
}
CStateGamePlay::~CStateGamePlay()
{
}
void CStateGamePlay::Init()
{
	CLoadBackground::GetInstance()->LoadBackgroundFromFile();

	CLoadObject::GetInstance()->LoadReSourceFromFile();
}
void CStateGamePlay::Update(float deltaTime)
{
	CLoadObject::GetInstance()->Update(deltaTime);
	//update cac Enemy
	CPoolObject::GetInstance()->Update(deltaTime);
	//update mario
	CMarioObject::GetInstance()->Update(deltaTime);
	//va cham voi Ground
	CMarioObject::GetInstance()->OnCollision(deltaTime, CBoxGround::GetInstance()->listGround);

	//va cham voi List Enemy
	CMarioObject::GetInstance()->OnCollision(deltaTime, CLoadObject::GetInstance()->m_listGameObject);//CPoolObject::GetInstance()->listEnemy);
	
}
void CStateGamePlay::Render()
{
	//CDrawObject::GetInstance()->Draw(CMarioObject::GetInstance(), D3DCOLOR_ARGB(127, 255, 255, 255));
	
	//ve map len man hinh
	CLoadBackground::GetInstance()->Draw();
	//ve mario
	CDrawObject::GetInstance()->Draw(CMarioObject::GetInstance());
	//ve cac doi tuong len man hinh
	CPoolObject::GetInstance()->Draw();
}
void CStateGamePlay::Destroy()
{

}