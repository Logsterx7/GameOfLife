#pragma once

#include "Pattern.hpp"

#include <cstdint>
#include <memory>
#include <vector>

class LifeSimulator
{
  public:
    LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY);

    void insertPattern(const Pattern& pattern, std::uint8_t startX, std::uint8_t startY);
    void update();

    std::uint8_t getSizeX() const;
    std::uint8_t getSizeY() const;
    bool getCell(std::uint8_t x, std::uint8_t y) const;

  private:
    int m_sizeX;
    int m_sizeY;
    std::vector<std::vector<bool>> m_grid;

    int countCells(int xPos, int Ypos);
};