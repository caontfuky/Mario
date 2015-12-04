#ifndef __CGAME_H__
#define __CGAME_H__

namespace GameMario
{
	class CGame
	{
	public:
		CGame();
		virtual ~CGame(){}
		virtual void Run();
		virtual void Exit();
		virtual void Pause();
		virtual void Resume();
		virtual void ProcessInput();
		bool IsAlive(){ return m_isAlived; };
		bool IsPause(){ return m_isPaused; };
	protected:
		virtual void Init() = 0;
		virtual void Destroy() = 0;
	protected:
		bool m_isAlived;
		bool m_isPaused;
	};
}
#endif // !__CGAME_H__
