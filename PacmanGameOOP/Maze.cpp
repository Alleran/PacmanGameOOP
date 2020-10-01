#include "Maze.hpp"
#include <SFML/Graphics.hpp>

Maze::Maze(Texture& texture) : m_mazeSize(0, 0), m_texture(texture)
{
}

void Maze::loadLevel(std::string levelName)
{
	Image levelData;
	if (!levelData.loadFromFile("assets/levels/" + levelName + ".png"))
	{
		throw std::runtime_error("Failed to load level (" + levelName + ")");
	}
	m_mazeSize = Vector2i(levelData.getSize());
	if (m_mazeSize.x < 15 || m_mazeSize.y < 15)
	{
		throw std::runtime_error("The loaded level is too small (min 15px)");
	}
	for (size_t y = 0; y < m_mazeSize.y; y++)
	{
		for (size_t x = 0; x < m_mazeSize.x; x++)
		{
			Color CellData = levelData.getPixel(x, y);

			if (CellData == Color::Black)
			{
				m_mazeData.push_back(Wall);
			}
			else if (CellData == Color::White)
			{
				m_mazeData.push_back(Dot);
			}
			else if (CellData == Color::Green)
			{
				m_mazeData.push_back(SuperDot);
			}
			else if (CellData == Color::Blue)
			{
				//pacboy position
				m_pacmanPosition = Vector2i(x, y);
				m_mazeData.push_back(Empty);
			}
			else if (CellData == Color::Red)
			{
				//ghost position
				m_ghostPositions.push_back(Vector2i(x, y));
				m_mazeData.push_back(Empty);
			}
			else
			{
				m_mazeData.push_back(Empty);
			}
		}
	}
	m_renderTexture.create(32 * m_mazeSize.x, 32 * m_mazeSize.y);
}
void Maze::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(Sprite(m_renderTexture.getTexture()), states);	
}

Vector2i Maze::indexToPosition(std::size_t index) const
{
	Vector2i position;

	position.x = index % m_mazeSize.x;
	position.y = index / m_mazeSize.x;

	return position;
}
Vector2i Maze::mapPixelToCell(Vector2f pixel) const
{
	Vector2i cell;
	cell.x = std::floor(pixel.x / 32.f);
	cell.y = std::floor(pixel.y / 32.f);

	return cell;
}

Vector2f Maze::mapCellToPixel(Vector2i cell) const
{
	Vector2f pixel;
	pixel.x = cell.x * 32 + 16;
	pixel.y = cell.y * 32 + 16;

	return pixel;
}

bool Maze::isWall(Vector2i position) const
{
	if (position.x < 0 || position.y < 0 || position.x >= m_mazeSize.x || position.y >= m_mazeSize.y)
		return false;

	return m_mazeData[positionToIndex(position)] == Wall;
}

void Maze::pickObject(Vector2i position)
{
	assert(!isWall(position));
	m_mazeData[positionToIndex(position)] = Empty;
}

int Maze::getRemainingDots() const
{
	int remainingDots = 0;

	for (unsigned int i = 0; i < m_mazeData.size(); i++)
	{
		if (m_mazeData[i] == Dot || m_mazeData[i] == SuperDot)
			remainingDots++;
	}

	return remainingDots;
}
