#include "Animator.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;

Animator::Animator(): m_duration(Time::Zero), m_isPlaying(false), m_loop(false), m_currentFrame(0)
{
}

void Animator::addFrame(IntRect frame)
{
    m_frames.push_back(frame);
}

void Animator::play(Time duration, bool loop)
{
    m_isPlaying = true;
    m_duration = duration;
    m_loop = loop;
}

bool Animator::isPlaying() const
{
    return m_isPlaying;
}

void Animator::update(Time diff)
{
}

void Animator::animate(Sprite& sprite)
{
    sprite.setTextureRect(m_frames[m_currentFrame]);
}