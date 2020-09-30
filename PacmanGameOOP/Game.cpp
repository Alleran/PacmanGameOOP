#include "Game.hpp"

Game::Game() :m_window(VideoMode(800, 600), "Pacman - the Game")
{
    if (!m_font.loadFromFile("assets/fonts/PAC-FONT.TTF"))
    {
        throw std::runtime_error("Font konnte nicht geladen werden");
    }    
    if (!m_logo.loadFromFile("assets/pacman_logo.png"))
    {
        throw std::runtime_error("Logo konnte nicht geladen werden");
    }
    if (!m_texture.loadFromFile("assets/texture.png"))
    {
        throw std::runtime_error("Texture konnte nicht geladen werden");
    }
    m_gameStates[GameState::NoCoin] = new NoCoinState(this);
    m_gameStates[GameState::Ready] = new ReadyState(this);
    m_gameStates[GameState::Playing] = new PlayingState(this);
    m_gameStates[GameState::Lost] = new LostState(this);
    m_gameStates[GameState::Win] = new WinState(this);
    changeGameState(GameState::NoCoin);
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
        m_currentState->update(seconds(1));
        m_window.clear();  
        //hier zeichnen
        m_currentState->draw(m_window);
        m_window.display();        
    }
}

void Game::changeGameState(GameState::State gameState)
{
    m_currentState = m_gameStates[gameState];
}