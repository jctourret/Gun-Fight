#ifndef MUSIC_H
#define MUSIC_H

#include "raylib.h"

namespace GunFight {
	class GameMusic {
		Music _song;
	public:
		GameMusic();
		~GameMusic();
		void playMusic();
		void updateMusic();
		void stopMusic();
	};
}
#endif