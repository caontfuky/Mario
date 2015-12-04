#ifndef __CVIEWWINDOWS_H__
#define __CVIEWWINDOWS_H__

#pragma once
#include "CSingleton.h"
#include "CGlobal.h"

class CViewWindows : public CSingleton<CViewWindows>
{
	friend class CSingleton<CViewWindows>;
protected:
	CViewWindows() : m_isFullScreen(false) {};
public:
	bool InitClienWindow();
	bool m_isFullScreen;
	static HWND m_hwndWindow;
	static HINSTANCE m_hInstance;
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
};

#endif // !__CVIEWWINDOWS_H__
