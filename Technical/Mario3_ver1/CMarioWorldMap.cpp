#include "CMarioWorldMap.h"
#include "CCamera.h"
#include "CCollision.h"
CMarioWorldMap::CMarioWorldMap()
{
	note = Note();
	this->m_imageCurr = new CTexture();
	this->m_imageCurr->LoadImageFromFile(MARIO_WM, D3DCOLOR_XRGB(0, 255, 255));
	this->m_drawImg = new CSprite();

	this->m_currentTime = 0;
	this->m_currentFrame = 0;
	this->m_elapseTimeChangeFrame = 0.1f;
	this->m_increase = 1;
	this->m_totalFrame = 2;
	this->m_column = 2;

	this->m_startFrame = 0;
	this->m_endFrame = 1;

	this->m_vx = 50;
	this->m_vy = 150;
	this->m_vxDefault = this->m_vx;
	this->m_vyDefault = this->m_vy;
	this->m_a = -300;
	this->m_aDefault = this->m_a;
	this->m_ax = 0;
	this->m_Width = 14;
	this->m_Height = 16;
	this->isMove = false;
	this->pos = note.pos;
}


CMarioWorldMap::~CMarioWorldMap()
{
}
void CMarioWorldMap::Update(float deltaTime)
{
	ChangeFrame(deltaTime);
	MoveUpdate(deltaTime);
	OnKeyDown(deltaTime);
}
void CMarioWorldMap::Draw()
{
	Vector3 p = Vector3();

	p = CCamera::GetInstance()->GetPointTransform(pos.x, pos.y + 90);

	this->m_drawImg->draw(m_imageCurr, this->GetRectRS(), p, D3DCOLOR_XRGB(255, 255, 255), true);
}

void CMarioWorldMap::SetFrame()
{}
void CMarioWorldMap::MoveUpdate(float deltaTime)
{
	if (isMove)
	{
		this->pos.x += this->m_vx * deltaTime;
		this->pos.y += this->m_vy *deltaTime;
	}
}
void CMarioWorldMap::SetNote(Note n)
{
	this->note = n;
	this->pos = this->note.pos;
}
void CMarioWorldMap::OnKeyDown(float deltaTime)
{
	if (CInput::GetInstance()->IsKeyDown(DIK_UP))
	{		
		if (this->note.Top == 1)
		{
			this->m_vx = 0;
			this->m_vy = 100;
			this->isMove = true;
		}
	}
	if (CInput::GetInstance()->IsKeyDown(DIK_DOWN))
	{
		if (this->note.Down == 1)
		{
			this->m_vx = 0;
			this->m_vy = -100;
			this->isMove = true;
		}
	}
	if (CInput::GetInstance()->IsKeyDown(DIK_LEFT))
	{
		if (this->note.Left == 1)
		{
			this->m_vx = -100;
			this->m_vy = 0;
			this->isMove = true;
		}
	}
	if (CInput::GetInstance()->IsKeyDown(DIK_RIGHT))
	{
		if (this->note.Right == 1)
		{
			this->m_vx = 100;
			this->m_vy = 0;
			this->isMove = true;
		}
	}
}
void CMarioWorldMap::OnkeyUp(float deltaTime)
{
}
void CMarioWorldMap::OnCollision(std::vector<Note> listNote)
{
	for (std::vector<Note>::iterator it = listNote.begin(); it != listNote.end(); it++)
	{
		Note n = *it;
		Box box = Box(n.pos.x, n.pos.y, n.width, n.height);
		if (this->note.stt != n.stt)
		{			
			if (CCollision::GetInstance()->AABBCheck(this->GetBox(), box))
			{
				isMove = false;
				this->SetNote(n);
			}
		}
	}
}
Box CMarioWorldMap::GetBox()
{	
	return Box(pos.x, pos.y, this->m_Width, this->m_Height, 0, 0);
}
RECT* CMarioWorldMap::GetRectRS()
{
	return this->UpdateRectResource(m_Height, m_Width);
}