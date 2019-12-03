#include "music.h"

using namespace GunFight;

namespace GunFight {
	static bool musicPlaying = true;
	static float songVolume = 0.33f;

	GameMusic::GameMusic() {
		_song = LoadMusicStream("../res/assets/snd/8-bit_West.ogg");
		PlayMusicStream(_song);
		SetMusicVolume(_song, songVolume);
	}

	GameMusic::~GameMusic() {
		musicPlaying = false;
		StopMusicStream(_song);
		UnloadMusicStream(_song);
	}

	void GameMusic::playMusic() {
		musicPlaying = true;
		ResumeMusicStream(_song);
	}
	void GameMusic::updateMusic() {
		if (IsKeyPressed(KEY_M) && musicPlaying == true) {
			stopMusic();
		}
		else if (IsKeyPressed(KEY_M) && musicPlaying == false) {
			playMusic();
		}

		if (musicPlaying == true)
			UpdateMusicStream(_song);
	}
	void GameMusic::stopMusic() {
		musicPlaying = false;
		PauseMusicStream(_song);
	}
}