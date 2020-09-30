#include "Pacman.hpp"
#include <SFML/Graphics.hpp>

Pacman::Pacman(Texture& texture): m_visual(texture), m_isDead(false)
{
}

void Pacman::die()
{
	m_isDead = true;
}

bool Pacman::isDead() const
{
	return m_isDead;
}

void Pacman::draw(RenderTarget& target, RenderStates states)
{
	states.transform *= getTransform();
	if (!m_isDead)
	{
		target.draw(m_visual, states);
	}
}
