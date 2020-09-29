// SFML.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

int main()
{
    Game pacMan;
    pacMan.run();
    return EXIT_SUCCESS;
}