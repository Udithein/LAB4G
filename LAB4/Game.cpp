#include "Game.h"
#include "Hero.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>
void Game::Update(int WinWidth, int WinHeight) {
	glPushMatrix();

	//glOrtho(0, WinWidth, WinHeight, 0, -1, 1);
	//glLoadIdentity();
	
	//std::cout << hero->position->y << std::endl;



	this->hero->Show();
	LogicForHero(this->hero);
	for (auto e : *level)
	{
		e->Show();
	}
		
	ge->Update();

	glPopMatrix();
}

void Game::LogicForHero(Hero* hero)
{
	double currentTime = glfwGetTime();
	double dt1 = currentTime - TimeBuffer;
	if (dt1>=0.5)
	{
		if ((hero->MoveXdirection != 0))
		{
			if ((hero->HeroStatement == 7))
			{
				hero->HeroStatement = 1;
			}
			else {
				hero->HeroStatement += 1;
			}
		}
		TimeBuffer = currentTime;
	}
}
