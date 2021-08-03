#ifndef SCREEN_H
#define SCREEN_H


namespace GunFight {
	const int screenWidth = 1280;
	const int screenHeight = 720;
	struct Resolution {
		int width;
		int height;
	};

	class Screen {
	private:
		Resolution _resolution;
	public:
		Screen();
		~Screen();
		void SetResolutionWidth(int width);
		void SetResolutionHeight(int height);
		int GetResolutionWidth();
		int GetResolutionHeight();
	};
}
#endif