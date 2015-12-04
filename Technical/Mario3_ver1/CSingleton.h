#ifndef __CSINGLETON_H__
#define __CSINGLETON_H__

template<class Singleton>
class CSingleton
{
public:
	static Singleton* GetInstance()
	{
		if (!s_pInstance)
		{
			s_pInstance = new Singleton();
		}
		return s_pInstance;
	}
public:
	static Singleton* s_pInstance;
};

template<class Singleton> Singleton* CSingleton<Singleton>::s_pInstance = nullptr;
#endif // !__CSINGLETON_H__
