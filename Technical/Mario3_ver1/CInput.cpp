#include "CInput.h"

CInput::CInput(void)
{
}

CInput::~CInput(void)
{
}

int CInput::InitInput(HINSTANCE hInstance)
{
	HRESULT result;

	result = DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_dinput, NULL);
	if (result != DI_OK)
		return 0;

	result = m_dinput->CreateDevice(GUID_SysKeyboard, &m_keyboard, NULL);
	if (result != DI_OK)
		return 0;

	return 1;
}

int CInput::InitKeyboard(HWND hWnd)
{
	HRESULT result;
	result = m_keyboard->SetDataFormat(&c_dfDIKeyboard);
	if (result != DI_OK)
		return 0;

	result = m_keyboard->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if (result != DI_OK)
		return 0;

	DIPROPDWORD dipdw;
	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = KEYBOARD_BUFFER_SIZE;
	m_keyboard->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);

	result = m_keyboard->Acquire();
	if (result != DI_OK)
		return 0;

	return 1;
}

void CInput::ProcessKeyboard()
{
	if (m_keyboard->GetDeviceState(sizeof(m_keyStates), (LPVOID)m_keyStates) != DI_OK)
	{
		m_keyboard->Acquire();
		m_keyboard->GetDeviceState(sizeof(m_keyStates), (LPVOID)m_keyStates);
	}
}

//int Input::KeyDown(int KeyCode)
//{
//	DWORD dwElements = KEYBOARD_BUFFER_SIZE;
//	HRESULT hr = _diddv->GetDeviceData( sizeof(DIDEVICEOBJECTDATA), _KeyEvents, &dwElements, 0 );
//
//	for( DWORD i = 0; i < dwElements; i++ ) 
//	{
//		int KeyCodeBuffer = _KeyEvents[i].dwOfs;
//		int KeyState = _KeyEvents[i].dwData;
//		if ( (KeyCode == KeyCodeBuffer) && ((KeyState & 0x80) > 0))
//			return 1;
//	}
//	return 0;
//}


void CInput::Update()
{
	//poll state of the keyboard
	m_keyboard->Poll();
	if (!SUCCEEDED(m_keyboard->GetDeviceState(256, (LPVOID)&m_keyStates)))
	{
		//keyboard device lost, try to re-acquire
		m_keyboard->Acquire();
	}
	// Collect all buffered events
	DWORD dwElements = KEYBOARD_BUFFER_SIZE;
	HRESULT hr = m_keyboard->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), m_keyEvents, &dwElements, 0);

	// Scan through all data, check if the key is pressed or released
	for (DWORD i = 0; i < dwElements; i++)
	{
		int KeyCode = m_keyEvents[i].dwOfs;
		int KeyState = m_keyEvents[i].dwData;
		if ((KeyState & 0x80) > 0)
			m_keyDown = KeyCode;
		else
			m_keyUP = KeyCode;
	}
}

int CInput::IsKeyDown(int KeyCode)
{
	return (m_keyStates[KeyCode] & 0x80) > 0;
}

int CInput::GetKeyDown()
{
	int tam = m_keyDown;
	m_keyDown = 0;
	return tam;
}
int CInput::GetKeyUp()
{
	int tam = m_keyUP;
	m_keyUP = 0;
	return tam;
}