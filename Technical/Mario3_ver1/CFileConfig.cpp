#include "CFileConfig.h"

CFileConfig::CFileConfig()
{

}

float CFileConfig::Sin(double angle){
	angle = (angle >= 0) ? angle : PI - angle;
	angle = (angle > 2 * PI) ? angle - (angle / (2 * PI))*(2 * PI) : angle;
	int radian = (angle / PI) * 180;
	radian = (radian > 360) ? radian - (radian / 360) * 360 : radian;
	switch (radian)
	{
	case 0:
		return 0;
	case 30:
		return 1 / 2;
	case 45:
		return sqrt(2) / 2;
	case 60:
		return sqrt(3) / 2;
	case 90:
		return sqrt(4) / 2;
	case 120:
		return sqrt(3) / 2;
	case 135:
		return sqrt(2) / 2;
	case 150:
		return 1 / 2;
	case 180:
		return 0;
	case 210:
		return -1 / 2;
	case 225:
		return -sqrt(2) / 2;
	case 240:
		return -sqrt(3) / 2;
	case 270:
		return -1;
	case 300:
		return -sqrt(3) / 2;
	case 315:
		return -sqrt(2) / 2;
	case 330:
		return -1 / 2;
	case 360:
		return 0;
	}
}

float CFileConfig::Cos(double angle){
	angle = (angle >= 0) ? angle : PI - angle;
	angle = (angle > 2 * PI) ? angle - (angle / (2 * PI))*(2 * PI) : angle;
	angle = PI / 2 - angle;
	return this->Sin(angle);
}

float CFileConfig::Tan(double angle){
	angle = (angle >= 0) ? angle : PI - angle;
	angle = (angle > 2 * PI) ? angle - (angle / (2 * PI))*(2 * PI) : angle;
	float sinValue = this->Sin(angle);
	float cosValue = this->Cos(angle);
	float tanValue = (cosValue != 0) ? sinValue / cosValue : MAXINT;
	return tanValue;
}

float CFileConfig::Cot(double angle){
	angle = (angle >= 0) ? angle : PI - angle;
	angle = (angle > 2 * PI) ? angle - (angle / (2 * PI))*(2 * PI) : angle;
	angle = PI / 2 - angle;
	return this->Tan(angle);
}

CFileConfig::~CFileConfig()
{

}