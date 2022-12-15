#pragma once
#define EnemyCount 12
struct Enemy {


	float xPos = 100.f;
	float yPos = 0.f;
	float Height = 100.f;
	float Width = 150.f;
	float movementSped = 5.f;
	bool isAlive = true;

	void Update();
	void Draw();
	void Sweep();
};

extern Enemy enemy[EnemyCount];