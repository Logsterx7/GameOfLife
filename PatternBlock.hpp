#pragma once
#include "Pattern.hpp"

#include <cstdint>

class PatternBlock : public Pattern
{
    // using Pattern::Pattern;
  public:
    std::uint8_t sizeX = 2;
    std::uint8_t sizeY = 2;
    bool patternGrid[2][2] = { { true, true },
                               { true, true } };
    virtual std::uint8_t getSizeX() const override;
    virtual std::uint8_t getSizeY() const override;
    virtual bool getCell(std::uint8_t x, std::uint8_t y) const override;
};