#include "Game.hpp"

Game::Game() :m_window(VideoMode(800, 600), "Pacman - the Game")
{

}

Game::~Game()
{
}

Font& Game::getFont()
{
    return m_font;
}

Texture& Game::getLogo()
{
	return m_logo;
}

Texture& Game::getTexture()
{
	return m_texture;
}

void Game::run()
{
    while (m_window.isOpen())
    {
        Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                m_window.close();
            }
            if (event.type == Event::KeyPressed)
            {   
                switch (event.key.code)
                {
                case Keyboard::I: m_currentState->insertCoin(); break;
                case Keyboard::Enter: m_currentState->pressBtnStart(); break;
                case Keyboard::W: m_currentState->moveJStick(Vector2i(0, +1)); break;
                case Keyboard::A: m_currentState->moveJStick(Vector2i(-1, 0)); break;
                case Keyboard::S: m_currentState->moveJStick(Vector2i(0, -1)); break;
                case Keyboard::D: m_currentState->moveJStick(Vector2i(+1, 0)); break;
                default:
                    break;
                }
            }
        }
        m_window.clear();        
        m_window.display();        
    }
}

void Game::changeGameState(GameState::State gameState)
{
    m_currentState = m_gameStates[gameState];
}