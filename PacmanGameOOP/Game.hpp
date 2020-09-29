#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;

class Game
{
public:
	Game();
	~Game();

	Font getFont();
	Texture getLogo();
	Texture getTexture();

	void run();
	void insertCoin();
	void pressBtnStart();
	void moveJStick(Vector2i direction);

private:
	RenderWindow m_window;
};

