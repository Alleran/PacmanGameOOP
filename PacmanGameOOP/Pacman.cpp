#include "Pacman.hpp"
#include <SFML/Graphics.hpp>

Pacman::Pacman(Texture& texture) : m_visual(texture), m_isDead(false), m_isDying(false)
{
	m_runAnimation.addFrame(IntRect(0, 32, 40, 40));
	m_runAnimation.addFrame(IntRect(0, 32 + 40, 40, 40));

	m_runAnimation.addFrame(IntRect(0, 32, 40, 40));
	m_runAnimation.addFrame(IntRect(0, 72 , 40, 40));
	m_runAnimation.addFrame(IntRect(0, 112, 40, 40));
	m_runAnimation.addFrame(IntRect(40, 112 , 40, 40));
	m_runAnimation.addFrame(IntRect(80, 112, 40, 40));
	m_runAnimation.addFrame(IntRect(120, 112 , 40, 40));
	m_runAnimation.addFrame(IntRect(160, 112, 40, 40));	

	m_runAnimation.play(seconds(0.25), true);
}

void Pacman::die()
{
	if (!m_isDying)
	{
		m_dieAnimation.play(seconds(1), false);
		m_isDying = true;
	}
}

bool Pacman::isDead() const
{
	return m_isDead;
}

bool Pacman::isDying() const
{
	return m_isDying;
}

void Pacman::update(Time diff)
{
	if (!m_isDead && !m_isDying)
	{
		m_runAnimation.update(diff);
		m_runAnimation.animate(m_visual);
	}
	else
	{
		m_dieAnimation.update(diff);
		m_dieAnimation.animate(m_visual);
		if (!m_dieAnimation.isPlaying())
		{
			m_isDying = false;
			m_isDead = true;
		}
	}
}

void Pacman::draw(RenderTarget& target, RenderStates states)
{
	states.transform *= getTransform();
	if (!m_isDead)
	{
		target.draw(m_visual, states);
	}
}