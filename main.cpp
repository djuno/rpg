

//#include <SDL2/SDL.h>
#include <stdio.h>
#include "Engine.h"


Engine engine;



int main(int argc, char* args[])
{



	if (!engine.init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!engine.loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			engine.run();

		}
	}

	//shut engine down
	engine.close();


	return 0;
}
