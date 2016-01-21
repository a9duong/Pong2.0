#pragma once

#include "game_state.h"
#include "paddle_player.h"
#include "ball.h"


class main_game : public tiny_state
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	paddle_player* player1;
	paddle_player* player2;
	ball* ballObject;
};