#include "CCollision.h"
#include <algorithm>

CCollision::CCollision()
{

}

CCollision::~CCollision()
{

}

//Toa do truyen vao la toa do trung tam
//first.x, first.y là toa do tai diem trung tam cua box
float CCollision::SweptAABB(Box first, Box second, float& normalx, float& normaly, float deltaTime)
{
	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;

	// find the distance between the objects on the near and far sides for both x and y
	if (first.vx > 0.0f)
	{
		xInvEntry = (second.x - second.w / 2) - (first.x + first.w / 2);
		xInvExit = (second.x + second.w / 2) - (first.x - first.w / 2);
	}
	else
	{
		xInvEntry = (second.x + second.w / 2) - (first.x - first.w / 2);
		xInvExit = (second.x - second.w / 2) - (first.x + first.w / 2);
	}

	if (first.vy > 0.0f)
	{
		yInvEntry = (first.y - first.h / 2) - (second.y + second.h / 2);
		yInvExit = (first.y + first.h / 2) - (second.y - second.h / 2);
	}
	else
	{
		yInvEntry = (second.y + second.h / 2) - (first.y - first.h / 2);
		yInvExit = (second.y - second.h / 2) - (first.y + first.h / 2);
	}

	// find time of collision and time of leaving for each axis (if statement is to prevent divide by zero)
	float xEntry, yEntry;
	float xExit, yExit;

	if (first.vx == 0.0f)
	{
		xEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		xEntry = xInvEntry / first.vx * deltaTime;
		xExit = xInvExit / first.vx * deltaTime;
	}

	if (first.vy == 0.0f)
	{
		yEntry = -std::numeric_limits<float>::infinity();
		yExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		yEntry = yInvEntry / first.vy * deltaTime;
		yExit = yInvExit / first.vy * deltaTime;
	}

	// find the earliest/latest times of collision
	float entryTime = std::max(xEntry, yEntry);
	float exitTime = std::min(xExit, yExit);

	// if there was no collision
	if (entryTime > exitTime || xEntry < 0.0f && yEntry < 0.0f || xEntry > 1.0f || yEntry > 1.0f)
	{
		normalx = 0.0f;
		normaly = 0.0f;
		return 1.0f;
	}
	else // if there was a collision
	{
		// calculate normal of collided surface
		if (xEntry > yEntry)
		{
			if (xInvEntry < 0.0f)
			{
				normalx = 1.0f;
				normaly = 0.0f;
			}
			else
			{
				normalx = -1.0f;
				normaly = 0.0f;
			}
		}
		else
		{
			if (yInvEntry < 0.0f)
			{
				normalx = 0.0f;
				normaly = 1.0f;
			}
			else
			{
				normalx = 0.0f;
				normaly = -1.0f;
			}
		}

		// return the time of collision
		return entryTime;
	}
}

Box CCollision::GetSweptBroadphaseBox(Box b, float deltaTime)
{
	Box broadphasebox;
	float posX;
	float posY;
	posX = b.vx > 0 ? (b.x - b.w / 2) : (b.x - b.w / 2) + b.vx * deltaTime;
	posY = b.vy > 0 ? (b.y + b.h / 2) + b.vy * deltaTime : (b.y + b.h / 2);
	broadphasebox.w = b.vx > 0 ? b.vx * deltaTime + b.w : b.w - b.vx * deltaTime;
	broadphasebox.h = b.vy > 0 ? b.vy * deltaTime + b.h : b.h - b.vy * deltaTime;
	broadphasebox.x = posX + broadphasebox.w / 2;
	broadphasebox.y = posY - broadphasebox.h / 2;
	return broadphasebox;
}

bool CCollision::AABBCheck(Box first, Box second, float& moveX, float& moveY, float& normalX, float& normalY)
{
	float l = (second.x - second.w / 2) - (first.x + first.w / 2);
	float r = (second.x + second.w / 2) - (first.x - first.w / 2);
	float t = (second.y + second.h / 2) - (first.y - first.h / 2);
	float b = (second.y - second.h / 2) - (first.y + first.h / 2);
	//Khong va cham
	if (l > 0 || r < 0 || t < 0 || b > 0)
	{
		moveX = 0;
		moveY = 0;
		normalX = 0;
		normalY = 0;
		return false;
	}
	//Xet truong hop ground
	moveX = (abs(l) < r) ? l : r;
	moveY = (abs(b) < t) ? b : t;
	//Loai tru truong hop hai doi tuong long nhau
	if (moveY >= second.h / 2)
	{
		moveX = 0;
		moveY = 0;
		normalX = 0;
		normalY = 0;
		return false;
	}
	if (abs(moveX) < abs(moveY))
	{
		moveY = 0.0f;
		normalX = (abs(l) > abs(r)) ? 1 : -1;
		normalY = 0;
	}
	else
	{
		moveX = 0.0f;
		normalY = (abs(t) < abs(b)) ? 1 : -1;
		normalX = 0;
	}
	return true;
}

bool CCollision::AABBCheck(Box first, Box second)
{
	return !((first.x + first.w / 2 < second.x - second.w / 2) ||
		(first.x - first.w / 2) > (second.x + second.w / 2) ||
		(first.y + first.h / 2) < (second.y - second.h / 2) ||
		(first.y - first.h / 2) > (second.y + second.h / 2));
}


float CCollision::Collision(CBaseGameObject* objectA, CBaseGameObject* objectB, float& normalx, float& normaly, float& moveX, float& moveY, float deltaTime)
{
	Box first = objectA->GetBox();
	Box second = objectB->GetBox();
	Box broadphaseBox = this->GetSweptBroadphaseBox(first, deltaTime);
	float collisiontime;
	if (AABBCheck(first, second, moveX, moveY, normalx, normaly))
	{
		return 2.0f;
	}
	else if (this->AABBCheck(broadphaseBox, second))
	{
		//Lay thoi gian co the va cham
		collisiontime = SweptAABB(first, second, normalx, normaly, deltaTime);
		if (collisiontime < 1.0f && collisiontime > 0.0f)
		{
			//Xay ra va cham trong frame tiep theo
			return collisiontime;
		}
	}
	else
	{
		return 1.0f;
	}
}

bool CCollision::Collision(CBaseGameObject* ObjectA, CBaseGameObject* ObjectB)
{
	return AABBCheck(ObjectA->GetBox(), ObjectB->GetBox());
}
bool CCollision::Collision(CBaseGameObject* ObjectA, Box box)
{
	return AABBCheck(ObjectA->GetBox(), box);
}
float CCollision::Collision(CBaseGameObject* ObjectA, Box box, float& normalx, float& normaly, float& moveX, float& moveY, float deltaTime)
{
	Box first = ObjectA->GetBox();
	Box second = box;
	Box broadphaseBox = this->GetSweptBroadphaseBox(first, deltaTime);
	float collisiontime;
	if (AABBCheck(first, second, moveX, moveY, normalx, normaly))
	{
		return 2.0f;
	}
	else if (this->AABBCheck(broadphaseBox, second))
	{
		//Lay thoi gian co the va cham
		collisiontime = CCollision::GetInstance()->SweptAABB(first, second, normalx, normaly, deltaTime);
		if (collisiontime < 1.0f && collisiontime > 0.0f)
		{
			//Xay ra va cham trong frame tiep theo
			return collisiontime;
		}
	}
	else
	{
		return 1.0f;
	}
}

bool CCollision::Collision(CBaseGameObject* ObjectA, std::vector<Box> listBox)
{
	
	for (std::vector<Box>::iterator it = listBox.begin(); it != listBox.end(); it++)
	{
		Box box = *it;
		//return AABBCheck(ObjectA->GetBox(), it);
	}
	return false;
}

