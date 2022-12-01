#include "Player.h"
#include "Engine.h"


Player player;

void Player::Update()
{

}

void Player::Draw()
{
	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	SDL_Rect rect = { xPos, yPos, Width, Height };
	SDL_RenderDrawRect(render, &rect);
	
}

