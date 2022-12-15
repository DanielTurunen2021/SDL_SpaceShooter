#pragma once




struct Player 
{

	float xPos = 800 - 100;
	float yPos = 1000.f;
	float Width = 100.f;
	float Height = 40.f;
	float movementSpeed = 1000.f;
	bool isActive = true;


	


	void Update();
	void Draw();
};

extern Player player;