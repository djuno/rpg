#pragma once
#include <stdio.h>
#include <SDL2/SDL.h>
#include "lua.h"
class Engine
{
public:
	Engine();
	~Engine();
	//main functions
	bool init();
	bool loadMedia();
	void run();
	void close();
	void draw();

private:
	//Screen dimension constants
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	//window to render to
	SDL_Window* gWindow = NULL;

	//The surface contained by the window
	SDL_Surface* gScreenSurface = NULL;

	//The image we will load and show on the screen
	SDL_Surface* gXOut = NULL;

	SDL_Surface* temp = NULL;

};
