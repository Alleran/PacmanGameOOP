#include "Dot.hpp"

CircleShape getDot()
{
    CircleShape dot;
    dot.setRadius(2);
    dot.setFillColor(Color::White);
    dot.setOrigin(2, 2);

    return dot;
}

CircleShape getSuperDot()
{
    CircleShape superDot;
    superDot.setRadius(4);
    superDot.setFillColor(Color::White);
    superDot.setOrigin(4, 4);

    return superDot;
}