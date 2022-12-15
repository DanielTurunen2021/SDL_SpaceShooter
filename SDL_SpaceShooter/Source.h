#pragma once
#include "SDL.h"
#include "Engine.h"
#include <stdio.h>


bool isRunning = true;
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

int Init_Video() {

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

}





int Init_Audio() 
{
	SDL_Init(SDL_INIT_AUDIO);


	if (SDL_Init(SDL_INIT_AUDIO) == -1) {

		printf("Failed to initialize SDL %s", SDL_GetError());
		isRunning = false;
		exit(-1);
	}
	else
	{
		printf("Audio init successful");
	}
}
	
