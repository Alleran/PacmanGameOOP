#pragma once
#include "Actor.hpp"
#include <SFML/Graphics.hpp>

class Pacman : 
    public Actor
{
public:
    Pacman(Texture& texture);
    void die();
    bool isDead() const;

private:
    void draw(RenderTarget& target, RenderStates states);
    bool m_isDead;
    Sprite m_visual;
};

