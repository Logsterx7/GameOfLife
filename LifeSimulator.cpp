#include "LifeSimulator.hpp"

#include "Pattern.hpp"
#include "iostream"

#include <cstdint>
#include <vector>

LifeSimulator::LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY)
{
    m_sizeX = sizeX;
    m_sizeY = sizeY;
    std::vector<std::vector<bool>> makeGrid(sizeY, std::vector<bool>(sizeX, false));

    // for grid
    for (int i = 0; i < sizeY; i++)
    {
        for (int j = 0; j < sizeX; j++)
        {
            makeGrid[i][j] = false;
        };
    };
    m_grid = makeGrid;
}

void LifeSimulator::insertPattern(const Pattern& pattern, std::uint8_t startX, std::uint8_t startY)
{

    unsigned int x = pattern.getSizeX();
    unsigned int y = pattern.getSizeY();

    for (unsigned int i = 0; i < y; i++)
    {
        for (unsigned int j = 0; j < x; j++)
        {
            if ((i + startY) >= 0 && (j + startX) >= 0 && (i + startY) < getSizeY() && (j + startX) < getSizeX())
            {
                m_grid[startY + static_cast<std::vector<std::vector<bool, std::allocator<bool>>, std::allocator<std::vector<bool, std::allocator<bool>>>>::size_type>(i)][startX + static_cast<std::vector<bool, std::allocator<bool>>::size_type>(j)] = pattern.getCell(j, i);
            }
        };
    };
}

int LifeSimulator::countCells(int xPos, int yPos)
{

    // starts in the top left corner relitave to starting cell
    xPos -= 1;
    yPos -= 1;
    int count = 0;
    // iterates through bordering cells
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((i + yPos) >= 0 && (j + xPos) >= 0 && (i + yPos) < getSizeY() && (j + xPos) < getSizeX())
            {

                if (getCell(j + xPos, i + yPos))
                {
                    // if j and i are both one we are 1, we don't need to count this cell since it's our starter cell
                    if (j == 1 && i == 1)
                    {
                        continue;
                    }
                    else
                    {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

void LifeSimulator::update()
{
    std::vector<std::vector<bool>> newGrid(getSizeY(), std::vector<bool>(getSizeX(), false));
    for (int i = 0; i < getSizeY(); i++)
    {
        for (int j = 0; j < getSizeX(); j++)
        {

            int cellCount = countCells(j, i);
            if (getCell(j, i))
            {
                if (cellCount < 2 || cellCount > 3)
                {
                    newGrid[i][j] = false;
                }

                else
                {
                    newGrid[i][j] = true;
                }
            }
            else
            {
                if (cellCount == 3)
                {
                    newGrid[i][j] = true;
                }
            }
        };
    };
    m_grid = newGrid;
}

std::uint8_t LifeSimulator::getSizeX() const
{
    return m_sizeX;
};
std::uint8_t LifeSimulator::getSizeY() const
{
    return m_sizeY;
};
bool LifeSimulator::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (y >= 0 && x >= 0 && y < getSizeY() && x < getSizeX())
    {
        return m_grid[y][x];
    }
    return false;
}