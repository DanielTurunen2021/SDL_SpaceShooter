#pragma once
#include "Enemy.h"

struct EnemyProjectile {


	float moveSpeed = 15.f;
	float xPos = 0;
	float yPos = 10.f;
	float Width = 20.f;
	float Height = 20.f;
	float shootTimer = 25.f;
	bool isActive = true;
	bool Shoot = false;

	void Update();
	void Draw();
	void Sweep();
};
extern EnemyProjectile enemyprojectile[12];