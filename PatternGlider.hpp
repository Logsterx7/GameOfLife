#pragma once
#include "Pattern.hpp"

#include <cstdint>

class PatternGlider : public Pattern
{
    // using Pattern::Pattern;
  public:
    int sizeX = 3;
    int sizeY = 3;
    bool patternGrid[3][3] = { { false, false, true },
                               { true, false, true },
                               { false, true, true } };
    virtual std::uint8_t getSizeX() const override;
    virtual std::uint8_t getSizeY() const override;
    virtual bool getCell(std::uint8_t x, std::uint8_t y) const override;
};