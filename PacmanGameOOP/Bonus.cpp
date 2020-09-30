#include "Bonus.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;

Bonus::Bonus(Texture& texture): m_visual(texture)
{
	m_visual.setOrigin(15, 15);
	setFruit(Banana);
}

void Bonus::setFruit(Fruit fruit)
{	
	switch (fruit)
	{
	case Bonus::Banana: m_visual.setTextureRect(IntRect(32, 0, 30, 30));
		break;
	case Bonus::Apple: m_visual.setTextureRect(IntRect(32 + 30, 0, 30, 30));
		break;
	case Bonus::Cherry: m_visual.setTextureRect(IntRect(32 + 60, 0, 30, 30));
		break;	
	}
}

void Bonus::draw(RenderTarget& target, RenderStates states)
{
	states.transform *= getTransform();
	target.draw(m_visual, states);
}