#include "PatternPulsar.hpp"

#include <cstdint>
#include <iostream>

std::uint8_t PatternPulsar::getSizeX() const
{
    return sizeX;
};

std::uint8_t PatternPulsar::getSizeY() const
{

    return sizeY;
};

bool PatternPulsar::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x < 0 || y < 0 || x >= sizeX || y >= sizeY)
    {
        return false;
    }

    return patternGrid[y][x];
};
