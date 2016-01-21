#pragma once

#include "paddle_player.h"

class ball : public Entity{
public:
	ball(paddle_player* player1, paddle_player* player2); 
	void Update();

private:
	paddle_player* player1;
	paddle_player* player2;
};