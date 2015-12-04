#ifndef __CGLOBAL_H__
#define __CGLOBAL_H__

#pragma once
#include <vector>
#include <string>
#include "d3d9.h"
#include "d3dx9.h"
#include <dinput.h>
#include <iostream>
#include <Windows.h>
#include <hash_map>
#include <sstream>
#include <math.h>

using namespace std;

//extern HWND e_hWND = nullptr;
//extern HINSTANCE e_hInstance = nullptr;

#define __FRAME_RATE 60
#define __SCREEN_WIDTH  512
#define __SCREEN_HEIGHT 470
#define __CLASS_NAME "Mario"
#define __CLASS_NAME__(x) #x

typedef unsigned long long __UINT64;
typedef long long		   __INT64;
typedef int 			   __INT32;
typedef unsigned int	   __UINT32;
typedef signed short	   __INT16;
typedef unsigned short	   __UINT16;
typedef signed char		   __INT8;
typedef unsigned char	   __UINT8;



typedef unsigned long long __UINT64;
typedef long long		   __INT64;
typedef int 			   __INT32;
typedef unsigned int	   __UINT32;
typedef signed short	   __INT16;
typedef unsigned short	   __UINT16;
typedef signed char		   __INT8;
typedef unsigned char	   __UINT8;

typedef LPDIRECT3DDEVICE9		Device;
typedef LPDIRECT3DSURFACE9		Surface;
typedef LPDIRECT3DTEXTURE9		Texture;
typedef LPD3DXSPRITE			Sprite;
typedef LPD3DXFONT				SpriteFont;
typedef LPDIRECT3D9				DirectX9;
typedef D3DXIMAGE_INFO			ImageInfo;
typedef D3DXVECTOR2				Vector2;
typedef D3DXVECTOR3				Vector3;
typedef D3DXVECTOR4				Vector4;
typedef LPDIRECTINPUT8			Input;
typedef LPDIRECTINPUTDEVICE8	InputDevice;
typedef DIDEVICEOBJECTDATA		DeviceObjectData;
typedef D3DXMATRIX				Matrix;
typedef D3DCOLOR				Color;
typedef RECT					Rect;

#define __OBJECT_PATH__ "..\\Resource\\File\\Object\\ObjectPath.csv"
#define __AUDIO_PATH__ "..\\Resource\\File\\Audio\\AudioPath.csv"
#define __SIMON_PATH__  "..\\Resource\\simon.png"
#define __BULLET_PATH__ "..\\Resource\\Bullet.png"
#define __CONTRA_PATH__ "..\\Resources\\contra_1.PNG"
//
#define __NAME_MAP_1__ "JUNGLE"
#define __NAME_MAP_3__ "WATERFALL"
#define __NAME_MAP_5__ "SNOW FIELD"
//
#define PI atan(1.0)*4
//#define PI 3.14
//#define PI 3.141592653589793
//#define PI boost::math::constants::pi<double>()

#endif // !__CGLOBAL_H__

struct Box
{
	Box()
	{
		x = y = 0;
		w = h = 0;
		vx = vy = 0;
	}

	Box(float _x, float _y, float _w, float _h, float _vx, float _vy)
	{
		x = _x;
		y = _y;
		w = _w;
		h = _h;
		vx = _vx;
		vy = _vy;
	}

	Box(D3DXVECTOR2 pos, float _w, float _h, float _vx, float _vy)
	{
		x = pos.x;
		y = pos.y;
		w = _w;
		h = _h;
		vx = _vx;
		vy = _vy;
	}

	Box(float _x, float _y, float _w, float _h)
	{
		x = _x;
		y = _y;
		w = _w;
		h = _h;
		vx = 0.0f;
		vy = 0.0f;
	}

	// position of top-left corner
	float x, y;

	// dimensions
	float w, h;

	// velocity
	float vx, vy;
};