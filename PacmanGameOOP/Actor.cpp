#include "Actor.hpp"

Actor::Actor() : m_currentFrame(0), m_loop(false), m_isPlaying(false), m_duration(Time())
{
}

void Actor::active(Time duration, bool loop)
{
    m_isPlaying = true;
    m_duration = duration;
    m_loop = loop;
}

void Actor::animate(Sprite& sprite)
{
    sprite.setTextureRect(m_frames[m_currentFrame]);
}

void Actor::update(Time diff)
{

}

void Actor::addFrame(IntRect frame)
{
    m_frames.push_back(frame);
}

bool Actor::isPlaying() const
{
    return false;
}
