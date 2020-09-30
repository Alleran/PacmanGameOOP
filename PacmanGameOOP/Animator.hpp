#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Animator
{
public:
	Animator();
	void addFrame(IntRect frame);
	void play(Time duration, bool loop);
	bool isPlaying() const;
	void update(Time diff);
	void animate(Sprite &sprite);
private:
	std::vector<IntRect> m_frames;
	bool m_isPlaying;
	Time m_duration;
	bool m_loop;
	uint16_t m_currentFrame;
};

