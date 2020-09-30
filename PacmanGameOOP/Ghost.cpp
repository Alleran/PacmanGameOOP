#include "Ghost.hpp"

Ghost::Ghost(Texture& texture): m_visual(texture), m_isWeak(false), m_weaknessDuration(Time::Zero)//, m_pacman(pacman)
{
    m_strongAnimator.addFrame(IntRect(40, 32, 40, 40));
    m_strongAnimator.addFrame(IntRect(80, 32, 40, 40));

    m_weakAnimator.addFrame(IntRect(40, 72, 40, 40));
    m_weakAnimator.addFrame(IntRect(80, 72, 40, 40));

    m_strongAnimator.play(seconds(0.25), true);
    m_weakAnimator.play(seconds(1), true);
}

void Ghost::setWeak(Time duration)
{
    m_isWeak = true;
    m_weaknessDuration = duration;
}

bool Ghost::isWeak() const
{
    return false;
}

void Ghost::update(Time diff)
{
    if (!m_isWeak)
    {
        m_strongAnimator.update(diff);
        m_strongAnimator.animate(m_visual);
    }
    else
    {
        m_weakAnimator.update(diff);
        m_weakAnimator.animate(m_visual);
    }
}

void Ghost::draw(RenderTarget& target, RenderStates states)
{
    states.transform *= getTransform();
    target.draw(m_visual, states);
}