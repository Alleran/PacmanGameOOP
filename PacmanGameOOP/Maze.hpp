#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <cassert>
using namespace sf;

class Maze :
    public Drawable
{
public:
    Maze(Texture& texture);
    void loadLevel(std::string levelName);
    inline Vector2i getPacmanPosition() { return m_pacmanPosition; }
    inline std::vector<Vector2i> getGhostsPositions() { return m_ghostPositions; }

    Vector2i indexToPosition(std::size_t index) const;
    inline size_t positionToIndex(Vector2i pos) const { return pos.y * m_mazeSize.x + pos.x; }

    Vector2i mapPixelToCell(Vector2f pixel) const;
    Vector2f mapCellToPixel(Vector2i cell) const;

    bool isWall(Vector2i position) const;
    inline bool isDot(Vector2i position) const { return m_mazeData[positionToIndex(position)] == Dot; }
    inline bool isSuperDot(Vector2i position) const { return m_mazeData[positionToIndex(position)] == SuperDot; }
    inline bool isBonus(Vector2i position) const { return m_mazeData[positionToIndex(position)] == Bonus; }
    void pickObject(Vector2i position);    

    inline Vector2i getSize() const { return m_mazeSize; }

    int getRemainingDots() const;
private:
    enum CellData {
        Empty, Wall, Dot, SuperDot, Bonus
    };
    void draw(RenderTarget& target, RenderStates states) const;
    Vector2i m_mazeSize;
    std::vector<CellData> m_mazeData;

    Vector2i m_pacmanPosition;
    std::vector<Vector2i> m_ghostPositions;

    RenderTexture m_renderTexture;
    Texture& m_texture;
};

