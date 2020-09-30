#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Bonus : public Drawable, public Transformable
{
public:
	enum Fruit {
		Banana,
		Apple,
		Cherry
	};
	Bonus(Texture& texture);
	void setFruit(Fruit fruit);

private:
	void draw(RenderTarget& target, RenderStates states);
	Sprite m_visual;
};