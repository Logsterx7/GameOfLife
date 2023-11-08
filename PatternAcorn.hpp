#pragma once
#include "Pattern.hpp"

#include <cstdint>

class PatternAcorn : public Pattern
{
    // using Pattern::Pattern;
  public:
    std::uint8_t sizeX = 7;
    std::uint8_t sizeY = 3;
    bool patternGrid[3][7] = { { false, true, false, false, false, false, false },
                               { false, false, false, true, false, false, false },
                               { true, true, false, false, true, true, true } };
    virtual std::uint8_t getSizeX() const override;
    virtual std::uint8_t getSizeY() const override;
    virtual bool getCell(std::uint8_t x, std::uint8_t y) const override;
};