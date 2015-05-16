#include "stdafx.h"
#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include <iostream>

Game::GameState Game::gameState = Uninitialized;
sf::RenderWindow Game::mainWindow;

void Game::Start(void)
{
	//If it's not uninitialized then it's not the first call so return
	if(gameState != Uninitialized) 
	{
		return;
	}

	//create a new window
	mainWindow.create(sf::VideoMode(1024,768,32), "Pong 2.0!");
	gameState = Game::ShowingSplash;

	while(!IsExiting())
	{
		GameLoop();
	}

	mainWindow.close();
}

bool Game::IsExiting()
{
	if(gameState == Game::Exiting) 
		return true;
	else 
		return false;
}

void Game::GameLoop()
{
	switch(gameState)
	{
	case Game::ShowingMenu:
		{
			ShowMenu();
			break;
		}
	case Game::ShowingSplash:
		{
			ShowSplashScreen();
			break;
		}
	case Game::Playing:
		{
			sf::Event currentEvent;
			while(mainWindow.pollEvent(currentEvent)) 
			{
				mainWindow.clear(sf::Color(255,0,0));
				mainWindow.display();

				if(currentEvent.type == sf::Event::Closed)
				{
					gameState = Game::Exiting;
				}

				if(currentEvent.type == sf::Event::KeyPressed)
				{
					if(currentEvent.key.code == sf::Keyboard::Escape) ShowMenu();
				}
			}
			break;
		}
	}
}

void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(mainWindow);
	gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(mainWindow);
	switch(result)
	{
	case MainMenu::Exit:
		gameState = Game::Exiting;
		break;
	case MainMenu::Play:
		gameState = Game::Playing;
		break;
	}
}

