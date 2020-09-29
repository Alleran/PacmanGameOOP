#include "GameState.hpp"

GameState::GameState(Game* game):m_game(game)
{
	
}

Game* GameState::getGameState() const
{
	return m_game;
}

NoCoinState::NoCoinState(Game* game):GameState(game)
{
}

void NoCoinState::insertCoin()
{
}

void NoCoinState::pressBtnStart()
{
}

void NoCoinState::moveJStick(Vector2i direction)
{
}

void NoCoinState::update(Time diff)
{
}

void NoCoinState::draw(RenderWindow& window)
{
}

bool NoCoinState::m_displayText()
{
	return false;
}

ReadyState::ReadyState(Game* game) :GameState(game)
{
}

void ReadyState::insertCoin()
{
}

void ReadyState::pressBtnStart()
{
}

void ReadyState::moveJStick(Vector2i direction)
{
}

void ReadyState::update(Time diff)
{
}

void ReadyState::draw(RenderWindow& window)
{
}

PlayingState::PlayingState(Game* game) :GameState(game)
{
}

void PlayingState::insertCoin()
{
}

void PlayingState::pressBtnStart()
{
}

void PlayingState::moveJStick(Vector2i direction)
{
}

void PlayingState::update(Time diff)
{
}

void PlayingState::draw(RenderWindow& window)
{
}

LostState::LostState(Game* game) :GameState(game)
{
}

void LostState::insertCoin()
{
}

void LostState::pressBtnStart()
{
}

void LostState::moveJStick(Vector2i direction)
{
}

void LostState::update(Time diff)
{
}

void LostState::draw(RenderWindow& window)
{
}

WinState::WinState(Game* game) :GameState(game)
{
}

void WinState::insertCoin()
{
}

void WinState::pressBtnStart()
{
}

void WinState::moveJStick(Vector2i direction)
{
}

void WinState::update(Time diff)
{
}

void WinState::draw(RenderWindow& window)
{
}
