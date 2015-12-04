#ifndef __CFILE_CONFIG_H__
#define __CFILE_CONFIG_H__

#include "CSingleton.h"
#include "CGlobal.h"


class CFileConfig : public CSingleton<CFileConfig>
{
	friend class CSingleton<CFileConfig>;
public:
	~CFileConfig();
	float Sin(double angle);
	float Cos(double angle);
	float Tan(double angle);
	float Cot(double angle);
protected:
	CFileConfig();
private:

};

#endif // !__CFILE_CONFIG_H__