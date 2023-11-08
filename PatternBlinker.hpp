#pragma once
#include "Pattern.hpp"

#include <cstdint>

class PatternBlinker : public Pattern
{
  public:
    const std::uint8_t sizeX = 1;
    const std::uint8_t sizeY = 3;
    bool patternGrid[3][1] = { { true },
                               { true },
                               { true } };
    virtual std::uint8_t getSizeX() const override;
    virtual std::uint8_t getSizeY() const override;
    virtual bool getCell(std::uint8_t x, std::uint8_t y) const override;
};