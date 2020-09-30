#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include "GameState.hpp"
using namespace sf;
using namespace std;

class Game
{
public:
	Game();
	~Game();

	Font &getFont();
	Texture &getLogo();
	Texture &getTexture();

	void run();
	void changeGameState(GameState::State gameState);
	//Im Branch "Game_Statuss_def"  wurden diese Funktionen der Ereignisschleife zugewiesen
	/*void insertCoin();
	void pressBtnStart();
	void moveJStick(Vector2i direction);*/

private:
	RenderWindow m_window;
	GameState* m_currentState;
	array<GameState*,GameState::State::Count> m_gameStates;
	Font m_font;
	Texture m_logo;
	Texture m_texture;
};

