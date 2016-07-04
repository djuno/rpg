#include "Engine.h"




Engine::Engine()
{

}


Engine::~Engine()
{

}

bool Engine::init()
{
	//Initialization flag
	bool success = true;
	printf("\ninitializing engine...");

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("test_engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	printf("\nengine initialized!\n");

	return success;
}

bool Engine::loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	printf("\nloading resources...");
	gXOut = SDL_LoadBMP("x.bmp");
	if (gXOut == NULL)
	{
		printf("\nUnable to load image %s! SDL Error: %s\n", "03_event_driven_programming/x.bmp", SDL_GetError());
		success = false;
	}
	printf("\nresources loaded!\n");
	return success;
}
void Engine::run()
{
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

			Lua script;
			script.Runfile("game.lua");
			//Apply the image
			SDL_BlitSurface(gXOut, NULL, gScreenSurface, NULL);

			//Update the surface
			SDL_UpdateWindowSurface(gWindow);



	}
}
void Engine::close()
{

	//Deallocate surface
	SDL_FreeSurface(gXOut);
	gXOut = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	printf("\nclosing...");
	//Quit SDL subsystems
	SDL_Quit();
}
void Engine::draw()
{

}
