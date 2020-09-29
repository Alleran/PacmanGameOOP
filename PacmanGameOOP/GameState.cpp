#include "GameState.hpp"
#include "Game.hpp"

GameState::GameState(Game* game):m_game(game)
{
	
}

Game* GameState::getGameState() const
{
	return m_game;
}

NoCoinState::NoCoinState(Game* game):GameState(game)
{
	m_sprite.setTexture(game->getLogo());
	m_sprite.setPosition(20, 50);

	m_text.setFont(game->getFont());
	m_text.setString("Bitte Mony");

	m_text.setPosition(220, 150);
	m_displayText = true;
}

void NoCoinState::insertCoin()
{
	getGameState()->changeGameState(GameState::Ready);
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

ReadyState::ReadyState(Game* game) :GameState(game)
{
	m_text.setFont(game->getFont());
	m_text.setString("Mit \"Enter\" starten sie ein Spiel...");
	m_text.setCharacterSize(14);

	m_text.setPosition(220, 150);	
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
	m_text.setFont(game->getFont());
	m_text.setString("YOU DIED");
	m_text.setCharacterSize(14);
	m_text.setPosition(220, 150);

	m_countdownText.setFont(game->getFont());
	m_countdownText.setCharacterSize(12);
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
	m_text.setFont(game->getFont());
	m_text.setString("Gewonnen - eine Gratis Runde...");
	m_text.setCharacterSize(14);
	m_text.setPosition(220, 150);
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
