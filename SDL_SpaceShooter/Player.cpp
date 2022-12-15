#include "Player.h"
#include "Engine.h"
#include "Projectile.h"
#include <stdio.h>
#include "Enemy.h"


Player player;

void Player::Update()
{


	if (keys[SDL_SCANCODE_D])
	{
		if (player.xPos < 1920 - 100) {
			player.xPos += 1000 * dt;
		}
		for (size_t i = 0; i < AmmoCount; i++)
		{
			if (projectile[i].Shoot == false) {
				projectile[i].xPos = player.xPos + player.Width / 2;
			}
		}	
	}
	if (keys[SDL_SCANCODE_A]) {
		if (player.xPos > 0) {
			player.xPos -= 1000 * dt;
		}
		for (size_t i = 0; i < AmmoCount; i++)
		{
			if (projectile[i].Shoot == false) {
				projectile[i].xPos = player.xPos; + player.Width / 2;
			}
		}
	}

	if (keys[SDL_SCANCODE_SPACE]) {
		for (size_t i = 0; i < AmmoCount; i++)
		{
			projectile[i].shootTimer -= dt;
			
			if (projectile[i].shootTimer <= 0) {
				projectile[i].Shoot = true;
				projectile[i].shootTimer = 0.1f;
			}
			
		}
	}
	for (size_t i = 0; i < AmmoCount; i++)
	{
		if (projectile[i].Shoot == true && projectile[i].yPos > projectile[i].yPos -5) {
			projectile[i].Update();
			projectile[i].Sweep();
			projectile[i].Draw();
		}

	}
}

void Player::Draw()
{
	SDL_Rect rect = { xPos, yPos, Width, Height };
	SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
	SDL_RenderDrawRect(render, &rect);
}