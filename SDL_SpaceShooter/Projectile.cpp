#include "Projectile.h"
#include "Engine.h"
#include "Enemy.h"
#include "Player.h"
#include <stdio.h>

Projectile projectile[AmmoCount];

void Projectile::Update() {
	for (size_t i = 0; i < AmmoCount; i++)
	{
		if (projectile[i].Shoot == true && projectile[i].yPos > 0) {
			projectile[i].yPos -= moveSpeed * dt;
		}
		if (projectile[i].yPos < 0 ) {
			projectile[i].yPos = player.yPos -200;
			projectile[i].xPos = player.xPos + player.Width / 2;
			projectile[i].Shoot = false;
		}
		if (projectile[i].Shoot == false) {
			projectile[i].yPos = player.yPos;
			projectile[i].xPos = player.xPos + player.Width / 2;
		}
	}
}

void Projectile::Sweep() {

	for (size_t i = 0; i < EnemyCount; i++)
	{

		
			if (projectile[i].yPos <= enemy[i].yPos + enemy[i].Height 
				&& projectile[i].xPos <= enemy[i].xPos + enemy[i].Width 
				&& projectile[i].xPos + projectile[i].Width >= enemy[i].xPos)
		{
			enemy[i].isAlive = false;
			projectile[i].Shoot = false;
		}
			if (projectile[i].Shoot == false) {
				projectile[i].yPos = player.yPos - player.Height;
				projectile[i].xPos = player.xPos + player.Width / 2;
			}
	}
		
}

void Projectile::Draw() {
	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
	SDL_Rect rect = { xPos, yPos, Width, Height };
	SDL_RenderDrawRect(render, &rect);
}