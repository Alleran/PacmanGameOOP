#pragma once
#include <SFML/Graphics.hpp>
#include "Pacman.hpp"
#include "Ghost.hpp"
using namespace sf;
class Game;

class GameState
{
public:
	enum State {
		NoCoin, Ready, Playing, Lost, Win, Count
	};
	GameState(Game* game);
	Game* getGameState() const;

	//Abstrakte Methoden	
	virtual void insertCoin() = 0;
	virtual void pressBtnStart() = 0;
	virtual void moveJStick(Vector2i direction) = 0;
	virtual void update(Time diff) = 0;
	virtual void draw(RenderWindow &window) = 0;

private:
	Game *m_game;	
};

class NoCoinState : public GameState {
public:
	NoCoinState(Game* game);
	void insertCoin();
	void pressBtnStart();
	void moveJStick(Vector2i direction);
	void update(Time diff);
	void draw(RenderWindow& window);
private:
	Text m_text;
	Sprite m_sprite;
	bool m_displayText;
};
class ReadyState : public GameState {
public:
	ReadyState(Game* game);
	void insertCoin();
	void pressBtnStart();
	void moveJStick(Vector2i direction);
	void update(Time diff);
	void draw(RenderWindow& window);
private:	
	Text m_text;
	//Pacman m_pacman;
};
class PlayingState : public GameState {
public:
	PlayingState(Game* game);
	void insertCoin();
	void pressBtnStart();
	void moveJStick(Vector2i direction);
	void update(Time diff);
	void draw(RenderWindow& window);
private:
	Pacman* m_pacman;
	std::vector<Ghost*> m_ghosts;	
};
class LostState : public GameState {
public:
	LostState(Game* game);
	void insertCoin();
	void pressBtnStart();
	void moveJStick(Vector2i direction);
	void update(Time diff);
	void draw(RenderWindow& window);
private:
	Text m_text;
	Time m_countdown;
	Text m_countdownText;
};
class WinState : public GameState {
public:
	WinState(Game* game);
	void insertCoin();
	void pressBtnStart();
	void moveJStick(Vector2i direction);
	void update(Time diff);
	void draw(RenderWindow& window);
private:
	Text m_text;	
};