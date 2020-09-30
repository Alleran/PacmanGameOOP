#pragma once
#include "Actor.hpp"
#include "Animator.hpp"
#include <SFML/Graphics.hpp>

class Pacman : 
    public Actor
{
public:
    Pacman(Texture& texture);
    void die();
    bool isDead() const;
    bool isDying() const;
    void update(Time diff);

private:
    void draw(RenderTarget& target, RenderStates states);
    bool m_isDead;
    bool m_isDying;
    Sprite m_visual;

    Animator m_runAnimation;
    Animator m_dieAnimation;
};

