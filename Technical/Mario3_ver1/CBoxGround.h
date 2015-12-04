#ifndef __CBOX_GROUND__H__
#define __CBOX_GROUND__H__
#pragma once
#include "CGlobal.h"
#include "CSingleton.h"
#include "CFileUtil.h"

#define FILE_LIST_BOX "..\\Resources\\Box\\Box.txt"
class CBoxGround : public CSingleton<CBoxGround>
{
public:
	CBoxGround();
	~CBoxGround();
public:
	std::vector<Box> listBox;

public:
	void Init();
	void LoadListBox(string filePath);
	
};
#endif;
