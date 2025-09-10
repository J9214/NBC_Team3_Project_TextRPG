#include <iostream>
#include "Sound.h"

using namespace std;

SoundManager* SoundManager::instance = nullptr;


SoundManager::SoundManager() 
{

}

SoundManager* SoundManager::GetInstance() 
{
	if (instance == nullptr) 
	{
		instance = new SoundManager();
	}

	return instance;
}

void SoundManager::PlayBGM(const std::string& filePath, float volume) 
{
	if (!bgm.openFromFile(filePath)) 
	{
		cout << "Error: BGM 파일을 열 수 없습니다 -> " << filePath << endl;
		return;
	}

	bgm.setLooping(true);
	bgm.setVolume(volume);
	bgm.play();      
}

void SoundManager::StopBGM() 
{
	bgm.stop();
}