#include "EnemyProjectile.h"
#include "Engine.h"
#include "Player.h"
#include<stdio.h>

EnemyProjectile enemyprojectile[12];

void EnemyProjectile::Draw(){

	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
	SDL_Rect rect = { xPos, yPos, Width, Height };
	SDL_RenderDrawRect(render, &rect);
}

void EnemyProjectile::Sweep() {


		for (size_t i = 0; i < 12; i++)
		{
			if (enemy[i].isAlive) {

				if (enemyprojectile[i].xPos + enemyprojectile[i].Width >= player.xPos &&
					enemyprojectile[i].xPos <= player.xPos + player.Width &&
					enemyprojectile[i].yPos + enemyprojectile[i].Height >= player.yPos &&
					enemyprojectile[i].yPos <= player.yPos + player.Height)
				{
					player.isActive = false;
					enemyprojectile[i].Shoot = false;
				}
				if (enemyprojectile[i].Shoot == false) {
					enemyprojectile[i].yPos = enemy[i].yPos + enemy[i].Height;
					enemyprojectile[i].xPos = enemy[i].xPos + +50;
				}
			}
		}
			
}


void EnemyProjectile::Update() {

	
	for (size_t i = 0; i < 12; i++)
	{
		if (enemy[i].isAlive) {
			enemyprojectile[i].xPos = enemy[i].xPos + 50;

			enemyprojectile[i].shootTimer -= dt;
			
			if (enemyprojectile[i].shootTimer <= 0) {
				enemyprojectile[i].Shoot = true;
				enemyprojectile[i].yPos += dt * moveSpeed;
				//enemyprojectile[i].shootTimer = 25.f;
			}

			if (enemyprojectile[i].Shoot == true && enemyprojectile[i].yPos > 1080) {
				enemyprojectile[i].yPos += moveSpeed * dt;
			}
			if (enemyprojectile[i].yPos > 1080) {
				enemyprojectile[i].yPos = enemy[i].yPos - 200;
				enemyprojectile[i].xPos = enemy[i].xPos + enemy[i].Width / 2;
				enemyprojectile[i].Shoot = false;
			}
			if (enemyprojectile[i].Shoot == false) {
				enemyprojectile[i].yPos = enemy[i].yPos;
				enemyprojectile[i].xPos = enemy[i].xPos + enemy[i].Width / 2;
			}
			if (shootTimer <= 0 && enemyprojectile[i].yPos >= 1080) {
				shootTimer = 25.f;
			}
		}
	}
		
}




