#ifndef __CSTATE_H__
#define __CSTATE_H__

class CState
{
public:
	CState();
	bool isChangeState =  false;
	virtual ~CState(){};
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;
	virtual void Destroy() = 0;
};

#endif // !__CSTATE_H__
