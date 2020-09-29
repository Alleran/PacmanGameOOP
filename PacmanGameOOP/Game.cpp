#include "Game.hpp"

Game::Game() :m_window(VideoMode(800, 600), "Pacman - the Game")
{

}

Game::~Game()
{
}

Font Game::getFont()
{
	return Font();
}

Texture Game::getLogo()
{
	return Texture();
}

Texture Game::getTexture()
{
	return Texture();
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
                case Keyboard::I: insertCoin(); break;
                case Keyboard::Enter: pressBtnStart(); break;
                case Keyboard::W: moveJStick(Vector2i(0, +1)); break;
                case Keyboard::A: moveJStick(Vector2i(-1, 0)); break;
                case Keyboard::S: moveJStick(Vector2i(0, -1)); break;
                case Keyboard::D: moveJStick(Vector2i(+1, 0)); break;               
                default:
                    break;
                }
            }
        }
        m_window.clear();        
        m_window.display();        
    }
}

void Game::insertCoin()
{
    cout << "Geldeinwurf" << endl;
}

void Game::pressBtnStart()
{
    cout << "Zum starten bitte \"Enter\" druecken." << endl;
}

void Game::moveJStick(Vector2i direction)
{
    cout << "Bewegen" << endl;
}