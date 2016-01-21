#include "main_game.h"
#include "main_menu.h"

void main_game::Initialize(sf::RenderWindow* window)
{
	this->player1 = new paddle_player(0);
	this->player2 = new paddle_player(1);
	this->player2->setPosition(window->getSize().x - this->player2->getGlobalBounds().width, 0);

	this->ballObject = new ball(this->player1, this->player2);
	this->ballObject->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}
void main_game::Update(sf::RenderWindow* window)
{
	this->ballObject->Update();
	this->player1->Update();
	this->player2->Update();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
		coreState.SetState(new main_menu());
	}
	
}
void main_game::Render(sf::RenderWindow* window)
{
	window->draw(*this->ballObject);
	window->draw(*this->player1);
	window->draw(*this->player2);
}
void main_game::Destroy(sf::RenderWindow* window)
{
	delete player1;
	delete player2;
}