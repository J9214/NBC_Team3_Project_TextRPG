#pragma once

#include <SFML/Audio.hpp>
#include <string>
#include <map>

class SoundManager 
{
private:

	SoundManager();

	sf::Music bgm;

	static SoundManager* instance;

public:

	SoundManager(const SoundManager&) = delete;
	void operator=(const SoundManager&) = delete;

	static SoundManager* GetInstance();

	void PlayBGM(const std::string& filePath, float volume = 50.0f);

	void StopBGM();
};