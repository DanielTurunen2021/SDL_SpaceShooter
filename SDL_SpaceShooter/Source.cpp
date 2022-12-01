#include "Engine.h"
#include <stdio.h>
#include "Player.h"

int main(int arg, char* args[]) {

	//The screen.
	Window = nullptr;
	render = nullptr;
	bool isRunning = true;
	extern Player player;


	//The image that gets rendered to the screen;
	SDL_Surface* ScreenSurface = NULL;
	SDL_Event event;

	//Screen resolution constants.
	const int SCREEN_WIDTH = 1920;
	const int SCREEN_HEIGHT = 1080;

	SDL_Init(SDL_INIT_VIDEO);


	if (SDL_Init(SDL_INIT_VIDEO) == -1) {

		printf("Failed to initialize SDL %s", SDL_GetError());
		isRunning = false;
		exit(-1);
	}
	else
	{
		Window = SDL_CreateWindow("Space shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		printf("Window was successfully created");
	}
		


	
	render = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

	while (isRunning)
	{


		while (SDL_PollEvent(&event))
		{
			{
				switch (event.type)
				{
				case SDL_QUIT:
					isRunning = false;
					break;

				case SDL_KEYDOWN:
				{
					int scancode = event.key.keysym.scancode;
					if (scancode == SDL_SCANCODE_ESCAPE)
						isRunning = false;

					keys[scancode] = true;

					break;
				}

				case SDL_KEYUP:
				{
					int scancode = event.key.keysym.scancode;
					keys[scancode] = false;

					break;
				}
				}
			}

		}
	}

	SDL_SetRenderDrawColor(render, 25, 25, 40, 255);
	SDL_RenderClear(render);

	player.Draw();
		

		//printf("Window was created successfully! \n");
		//isRunning = true;





		//SDL_SetRenderDrawColor(render, 0, 0, 0, SDL_ALPHA_OPAQUE);
		//SDL_RenderClear(render);
		//SDL_SetRenderDrawColor(render, 255, 255, 255, SDL_ALPHA_OPAQUE);
		//SDL_RenderPresent(render);





		//if (Window == NULL) {
		//	printf("Window could not be created! SDL error: %s", SDL_GetError());
		//	exit(-1);
		//}
		//else
		//{
			//If the window creation successful, get the surface, fill surface with an RGB color and update the surface with that color.
		//ScreenSurface = SDL_GetWindowSurface(Window);
		//SDL_FillRect(ScreenSurface, NULL, SDL_MapRGB(ScreenSurface->format, 255, 255, 255));
		//
		//SDL_UpdateWindowSurface(Window);

		//while loop to keep the window open.
		//SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
	//}
	}






	SDLinit()












		//printf("Initializing SDL\n");
		//
		//
		//
		//
		//
		//printf("Player was drawn");
		//
		//
		//
		//printf("Shutting down subsystems...\n");
		//SDL_Quit();
		//SDL_DestroyWindow(Window);
		//
		//
		//exit(0);
//}

	