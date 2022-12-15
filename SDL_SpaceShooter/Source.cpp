#include "Engine.h"
#include <stdio.h>
#include "Player.h"
#include "Enemy.h"
#include "Source.h"
#include "EnemyProjectile.h"

int main(int arg, char* args[]) {


	Window = nullptr;
	render = nullptr;
	float offset = 150.f;




	//The image that gets rendered to the screen;
	SDL_Surface* ScreenSurface = NULL;
	SDL_Event event;

	//Screen resolution constants.


	Init_Video();
	Init_Audio();




	render = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

	auto tp = SDL_GetTicks64();

	while (isRunning)
	{

		//Calculate delta time.
		auto newTP = SDL_GetTicks64();
		auto Difference = newTP - tp;
		dt = static_cast<float>(Difference) / 1000.0f;
		tp = newTP;









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
					{
						SDL_DestroyWindow(Window);
						isRunning = false;
					}

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

		ScreenSurface = SDL_GetWindowSurface(Window);
		SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
		SDL_RenderClear(render);


		if (player.isActive) {
			player.Update();
			player.Draw();
		}
		

		for (size_t i = 0; i < EnemyCount; i++)
		{
			if (enemy[i].isAlive) {

				enemy[i].Draw();
				enemy[i].Update();
				enemy[i].Sweep();
				enemyprojectile[i].Draw();
				enemyprojectile[i].Update();
				enemyprojectile[i].Sweep();
			}
			enemy[i].xPos = i * offset;
		}
		SDL_RenderPresent(render);
	}

}
	