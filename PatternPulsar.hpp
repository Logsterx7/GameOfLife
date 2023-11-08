#pragma once
#include "Pattern.hpp"

#include <cstdint>

class PatternPulsar : public Pattern
{
    // using Pattern::Pattern;
  public:
    int sizeX = 13;
    int sizeY = 13;
    bool patternGrid[13][13] = {
        { false, false, true, true, true, false, false, false, true, true, true, false, false },
        { false, false, false, false, false, false, false, false, false, false, false, false, false },
        { true, false, false, false, false, true, false, true, false, false, false, false, true },
        { true, false, false, false, false, true, false, true, false, false, false, false, true },
        { true, false, false, false, false, true, false, true, false, false, false, false, true },
        { false, false, true, true, true, false, false, false, true, true, true, false, false },
        { false, false, false, false, false, false, false, false, false, false, false, false, false },
        { false, false, true, true, true, false, false, false, true, true, true, false, false },
        { true, false, false, false, false, true, false, true, false, false, false, false, true },
        { true, false, false, false, false, true, false, true, false, false, false, false, true },
        { true, false, false, false, false, true, false, true, false, false, false, false, true },
        { false, false, false, false, false, false, false, false, false, false, false, false, false },
        { false, false, true, true, true, false, false, false, true, true, true, false, false }
    };
    virtual std::uint8_t getSizeX() const override;
    virtual std::uint8_t getSizeY() const override;
    virtual bool getCell(std::uint8_t x, std::uint8_t y) const override;
};
