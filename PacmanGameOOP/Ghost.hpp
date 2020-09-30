#pragma once
#include "Actor.hpp"
#include "Pacman.hpp"

class Ghost :
    public Actor
{
public:
    enum State {
        Strong, Weak, 
    };

    Ghost(Texture & texture);

    void setWeak(Time duration);
    bool isWeak() const;
    void update(Time diff);
private:
    void draw(RenderTarget& target, RenderStates states);
    bool m_isWeak;
    Time m_weaknessDuration;    
    Pacman* m_pacman;
    Sprite m_visual;
};