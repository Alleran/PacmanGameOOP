#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Actor: public Transformable, public Drawable
{
public:
	Actor();

	void active(Time duration, bool loop);
	void animate(Sprite& sprite);
	void update(Time diff);
	void addFrame(IntRect frame);
	bool isPlaying() const;
private:
	std::vector<IntRect> m_frames;
	bool m_isPlaying;
	bool m_loop;
	Time m_duration;
	uint16_t m_currentFrame;
};