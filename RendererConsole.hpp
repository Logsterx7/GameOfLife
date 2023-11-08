#pragma once

#include "LifeSimulator.hpp"
#include "Renderer.hpp"

#include <vector>

class RendererConsole : public Renderer
{
  public:
    virtual void render(const LifeSimulator& simulation) override;

  private:
    std::vector<std::vector<bool>> previousState;
};