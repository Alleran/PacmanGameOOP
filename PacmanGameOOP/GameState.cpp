#include "GameState.hpp"
#include "Game.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

template <typename T>
void centerDraw(T& drawing) {
	FloatRect bound = drawing.getLocalBounds();
	drawing.setOrigin(bound.width / 2, bound.height / 2);
}

GameState::GameState(Game* game) :m_game(game)
{

}

Game* GameState::getGameState() const
{
	return m_game;
}

NoCoinState::NoCoinState(Game* game) :GameState(game)
{
	m_sprite.setTexture(game->getLogo());
	m_sprite.setPosition(20, 50);
	m_sprite.setScale(0.5, 0.5);

	m_text.setFont(game->getFont());
	m_text.setString("Bitte Coin einwerfen mit \"I\"");

	centerDraw(m_text);
	m_text.setPosition(400, 300);
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
	window.draw(m_sprite);
	window.draw(m_text);
}

ReadyState::ReadyState(Game* game) :GameState(game)
{
	m_text.setFont(game->getFont());
	m_text.setString("Mit \"Enter\" starten sie ein Spiel...");
	m_text.setCharacterSize(24);

	centerDraw(m_text);
	m_text.setPosition(400, 300);
}

void ReadyState::insertCoin()
{
}

void ReadyState::pressBtnStart()
{
	getGameState()->changeGameState(GameState::Playing);
}

void ReadyState::moveJStick(Vector2i direction)
{	
}

void ReadyState::update(Time diff)
{
}

void ReadyState::draw(RenderWindow& window)
{
	window.draw(m_text);
}

PlayingState::PlayingState(Game* game) :GameState(game), m_ghost(game->getTexture()), m_pacman(game->getTexture())
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
	//Nur zu Testzwecken
	if (direction.x == -1)
	{
		getGameState()->changeGameState(GameState::Lost);
	}
	else if (direction.x == 1)
	{
		getGameState()->changeGameState(GameState::Win);
	}
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
	m_text.setCharacterSize(42);
	centerDraw(m_text);
	m_text.setPosition(400, 300);


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
	m_countdown += diff;
	if (m_countdown.asSeconds() >= 10)
	{	
		getGameState()->changeGameState(GameState::Ready);
	}
	m_countdownText.setString("Für weiter einen weiteren Coin einwerfen");
}

void LostState::draw(RenderWindow& window)
{
	window.draw(m_text);
	window.draw(m_countdownText);
}

WinState::WinState(Game* game) :GameState(game)
{
	m_text.setFont(game->getFont());
	m_text.setString("Gewonnen - eine Gratis Runde...");
	m_text.setCharacterSize(42);
	centerDraw(m_text);
	m_text.setPosition(400, 300);
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
	static Time timeBuffer = Time::Zero;
	timeBuffer += diff;

	if (timeBuffer.asSeconds() > 10)
	{	
		getGameState()->changeGameState(GameState::Ready);
	}
}

void WinState::draw(RenderWindow& window)
{
	window.draw(m_text);
}
