#ifndef __CMOVE_H__
#define __CMOVE_H__

class CMove
{
public:
	CMove() : m_vx(0),
		m_vy(0),
		m_vxDefault(0),
		m_vyDefault(0),
		m_a(0),
		m_ax(0),
		m_isMoveLeft(true),
		m_isMoveRight(false),
		m_isJumping(false),
		m_canJump(false),
		m_jumpMax(0){};
	~CMove(){};
public:
	float m_vxDefault;
	float m_vyDefault;
	float m_vx;
	float m_vy;
	float m_a;
	float m_ax;
	float m_aDefault;
	bool m_isMoveLeft;
	bool m_isMoveRight;
	bool m_isJumping;
	bool m_canJump;
	float m_jumpMax;
	virtual void MoveUpdate(float deltaTime) = 0;
};


#endif // !__CMOVE_H__
