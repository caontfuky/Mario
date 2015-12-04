#ifndef __CINPUT_H__
#define __CINPUT_H__

#include "CGlobal.h"
#include "CSingleton.h"
#include <dinput.h>

#define KEYBOARD_BUFFER_SIZE 256
class CInput : public CSingleton<CInput>
{
	friend class CSingleton<CInput>;
protected:
	CInput(void);
	LPDIRECTINPUT8 m_dinput;
	LPDIRECTINPUTDEVICE8 m_keyboard;

	int Keyboard_Buffer_Size;
	BYTE  m_keyStates[256];
	DIDEVICEOBJECTDATA m_keyEvents[KEYBOARD_BUFFER_SIZE];
	int m_keyUP;
	int m_keyDown;

public:
	~CInput(void);
	int InitInput(HINSTANCE hInstance);
	int InitKeyboard(HWND hWnd);
	// Lấy trạng thái bàn phím
	void ProcessKeyboard();
	//// Xử lí keydown = buffer
	//int KeyDown(int KeyCode);
	//Update KeyState tu KeyEvents
	void Update();
	//Lay trang thai phim voi "key"
	BYTE GetKeyState(int key) { return m_keyStates[key]; }
	// Xử lí keydown
	int IsKeyDown(int KeyCode);
	int GetKeyDown();
	int GetKeyUp();

};
#endif // !__CINPUT_H__
