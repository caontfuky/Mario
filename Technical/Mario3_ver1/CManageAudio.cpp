#include "CManageAudio.h"
#include "CFileUtil.h"

ManageAudio::ManageAudio(void)
{
	_Music_Background = true;
	_Sound = true;
}

int ManageAudio::init_DirectSound(HWND hWnd)
{
	HRESULT result;

	//create Direct Manage Sound Object
	soundManage = new CSoundManager();

	//initializa DirectSound
	result = soundManage->Initialize(hWnd, DSSCL_PRIORITY);
	if (result != DS_OK)
		return 0;

	//set the primaty buffer format
	result = soundManage->SetPrimaryBufferFormat(2, 22050, 16);
	if (result != DS_OK)
		return 0;

	//return success
	return 1;
}

void ManageAudio::addSound(int key, bool loop, std::string fileName)
{
	CSound* sound = this->loadSound(loop, fileName);
	this->listAudio[key] = sound;
}

CSound* ManageAudio::loadSound(bool loop, std::string fileName)
{
	HRESULT result;

	CSound *wave;

	result = soundManage->Create(&wave, (char*)fileName.c_str());
	if (result != DS_OK)
		return NULL;

	wave->loop = loop;
	return wave;
}

void ManageAudio::playSound(TypeAudio _type)
{
	
	this->stopSound(_type);
	std::hash_map<int, CSound*>::iterator it = this->listAudio.find((int)_type);
	if (it != this->listAudio.end())
	{
		CSound* sound = it->second;

		if (sound->loop)
		{
			sound->Reset();
			sound->Play(0, DSBPLAY_LOOPING);
			//sound->Play(0, DSSCL_PRIORITY);
		}
		else
		{
			sound->Reset();
			sound->Play();
		}
	}
}

void ManageAudio::loopSound(CSound *sound)
{
	sound->Play(0, DSSCL_PRIORITY);
}

void ManageAudio::stopSound(TypeAudio _type)
{
	std::hash_map<int, CSound*>::iterator it = this->listAudio.find((int)_type);
	if (it != this->listAudio.end())
	{
		CSound* sound = it->second;
		if (sound->IsSoundPlaying())
		{
			sound->Stop();
		}
	}
}


void ManageAudio::readFileAudio()
{
	int id;
	std::string pathItem;
	bool loop;
	std::vector<std::string> result = CFileUtil::GetInstance()->LoadFromFile(AUDIO_PATH);
	std::vector<std::string> item; //Lay tung item trong result
	for (int i = 0; i < result.size(); i++)
	{
		item = CFileUtil::GetInstance()->Split(result.at(i).c_str(), ',');
		id = atoi(item.at(0).c_str());
		loop = (bool)atoi(item.at(1).c_str());
		pathItem = item.at(2).c_str();
		ManageAudio::GetInstance()->addSound(id, loop, pathItem);
	}
}

ManageAudio::~ManageAudio(void)
{
}
