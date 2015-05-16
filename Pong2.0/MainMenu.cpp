#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{
	sf::Texture texture;
	texture.loadFromFile("images/mainmenu.png");
	sf::Sprite sprite(texture);

	//Setup the clickable regions
	MenuItem playButton;
	playButton.rect.top = 145;
	playButton.rect.left = 0;
	playButton.rect.height = 380;
	playButton.rect.width = 1023;

	MenuItem exitButton;
	exitButton.rect.top = 383;
	exitButton.rect.left = 0;
	exitButton.rect.height = 560;
	exitButton.rect.width = 1023;

	MenuItem creditsButton;
	exitButton.rect.top = 679;
	exitButton.rect.left = 841;
	exitButton.rect.height = 87;
	exitButton.rect.width = 174;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);
	_menuItems.push_back(creditsButton);

	window.draw(sprite);
	window.display();

	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator i;

	for(i = _menuItems.begin(); i != _menuItems.end(); ++i)
	{
		sf::Rect<int> menuItemRect = i->rect;
		if( x > menuItemRect.left
			&& x < menuItemRect.left + menuItemRect.width
			&& y > menuItemRect.top  
			&& y < menuItemRect.height + menuItemRect.top)
		{
			return i->action;
		}
	}

	return MainMenu::Nothing;
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;
	while(true)
	{
		while(window.pollEvent(menuEvent))
		{
			if(menuEvent.type == sf::Event::MouseButtonPressed)
			{
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if(menuEvent.type == sf::Event::Closed)
			{
				return Exit;
			}
		}
	}
}