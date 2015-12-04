#include "CBoxGround.h"


CBoxGround::CBoxGround()
{
	//Init();
	LoadListBox(FILE_LIST_BOX);
}


CBoxGround::~CBoxGround()
{
}
void CBoxGround::Init()
{
	Box c = Box(300, 457, 100, 100);

	Box b = Box(100, 457, 800, 50);
	
	this->listBox.push_back(c);
	this->listBox.push_back(b);
	


	/*for (int i = 0; i < 1; i++)
	{
		Box box = Box(i * 200, 450, 100, 100);
		this->listBox.push_back(box);
		
	}*/
}
void CBoxGround::LoadListBox(string filePath)
{
	std::vector<std::string> value = CFileUtil::GetInstance()->LoadFromFile(filePath);
	std::vector<std::string> result; //Luu chuoi sau khi duoc cat
	for (int i = 0; i < value.size(); i++)
	{
		result = CFileUtil::GetInstance()->Split(value.at(i).c_str(), '\t');

		float x = std::atoi(result.at(0).c_str());
		float y = std::atoi(result.at(1).c_str());
		float w = std::atoi(result.at(2).c_str());
		float h = std::atoi(result.at(3).c_str());
		

		Box box = Box(x, y, w, h);

		this->listBox.push_back(box);
	}
}