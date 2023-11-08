#include "PatternGlider.hpp"

#include <cstdint>
#include <iostream>

std::uint8_t PatternGlider::getSizeX() const
{
    return sizeX;
};

std::uint8_t PatternGlider::getSizeY() const
{

    return sizeY;
};

bool PatternGlider::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x < 0 || y < 0 || x >= sizeX || y >= sizeY)
    {
        return false;
    }

    return patternGrid[y][x];
};
