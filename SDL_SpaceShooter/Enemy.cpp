#include "Enemy.h"
#include "Engine.h"
#include "Player.h"
#include<stdio.h>


Enemy enemy[EnemyCount];

void Enemy::Update() {

	for (size_t i = 0; i < EnemyCount; i++)
	{
		if(enemy[i].isAlive)
		enemy[i].yPos += movementSped * dt;
	}	
}

void Enemy::Draw() {

			SDL_Rect rect = { xPos, yPos, Width, Height };
			SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
			SDL_RenderDrawRect(render, &rect);	
}

void Enemy::Sweep() {
	for (size_t i = 0; i < EnemyCount; i++)
	{
		if (enemy[i].isAlive) {

			if (player.xPos + player.Width >= enemy[i].xPos &&
				player.xPos <= enemy[i].xPos + enemy[i].Width &&
				player.yPos + player.Height >= enemy[i].yPos &&
				player.yPos <= enemy[i].yPos + enemy[i].Height) {


				player.isActive = false;
				enemy[i].isAlive = false;
			}
		}
	}
		
}
