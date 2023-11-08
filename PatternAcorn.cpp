#include "PatternAcorn.hpp"

#include <cstdint>
#include <iostream>

std::uint8_t PatternAcorn::getSizeX() const
{
    return sizeX;
};

std::uint8_t PatternAcorn::getSizeY() const
{

    return sizeY;
};

bool PatternAcorn::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x < 0 || y < 0 || x >= sizeX || y >= sizeY)
    {
        return false;
    }

    return patternGrid[y][x];
};

;