#include "RendererConsole.hpp"

#include "rlutil.h"

#include <iostream>

void RendererConsole::render(const LifeSimulator& simulation)
{
    previousState.size();
    int sizeY = simulation.getSizeY();
    int sizeX = simulation.getSizeX();

    if (previousState.size() == 0)
    {
        std::vector<std::vector<bool>> makeGrid(sizeY, std::vector<bool>(sizeX, false));
        for (int i = 0; i < sizeY; i++)
        {
            for (int j = 0; j < sizeX; j++)
            {
                makeGrid[i][j] = simulation.getCell(j, i);
                rlutil::locate(j + 1, i + 1);
                if (simulation.getCell(j, i))
                {
                    rlutil::setChar('X');
                }
                else
                {
                    rlutil::setChar(' ');
                }
            }
        }
        previousState = makeGrid;
    }
    else
    {
        for (int i = 0; i < sizeY; i++)
        {
            for (int j = 0; j < sizeX; j++)
            {

                if (previousState[i][j] != simulation.getCell(j, i))
                {

                    rlutil::locate(j + 1, i + 1);
                    if (simulation.getCell(j, i))
                    {
                        rlutil::setChar('X');
                    }
                    else
                    {
                        rlutil::setChar(' ');
                    }
                    previousState[i][j] = simulation.getCell(j, i);
                }
            }
        }
    }
}