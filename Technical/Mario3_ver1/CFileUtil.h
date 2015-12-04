#ifndef __CFILE_UTIL_H__
#define __CFILE_UTIL_H__

#include "CSingleton.h"
#include "CGlobal.h"
#include <fstream>

class CFileUtil : public CSingleton<CFileUtil>
{
	friend class CSingleton<CFileUtil>;
public:
	/**
	/* File ultil dùng để xử lý file, chỉ đọc thông tin từ file lên và xử lý sơ lược, cung cấp
	/* các hàm hổ trợ việc đọc file
	/*
	*/
	~CFileUtil();
	std::vector<std::string> LoadFromFile(const std::string& filePath); // Ham nay load file len va tra ve mang string
	//std::hash_map<int, std::string> LoadFromFile(const std::string& filePath); //Sau nay neu cau hinh doi tuong, can dung
	//hash_map<int, std::string> LoadFromFile(const std::string& filePath); //
	//int** LoadFromFile(const std::string& filePath); // Dung load bachground
	std::vector<std::string> Split(const std::string&, char); //Ham nay dung de xu ly chuoi
protected:
	ifstream* m_reader;
	CFileUtil();
};


#endif // !__CFILE_UTIL_H__
