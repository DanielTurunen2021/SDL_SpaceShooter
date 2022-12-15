#pragma once
#include "Player.h"
#define AmmoCount 12

struct Projectile
{
	float moveSpeed = 100.f;
	float xPos = player.xPos + player.Width/2;
	float yPos = player.yPos;
	float Width = 20.f;
	float Height = 20.f;
	float shootTimer = 0.1f;
	bool isActive = true;
	bool Shoot = false;

	void Update();
	void Draw();
	void Sweep();
};

extern Projectile projectile[AmmoCount];