#include "LifeSimulator.hpp"
#include "PatternAcorn.hpp"
#include "PatternBlinker.hpp"
#include "PatternBlock.hpp"
#include "PatternGlider.hpp"
#include "PatternGosperGliderGun.hpp"
#include "PatternPulsar.hpp"
#include "RendererConsole.hpp"
#include "rlutil.h"

#include <cstdint>
#include <iostream>
#include <thread>
#include <vector>
int main()
{
    int cols = static_cast<int>(rlutil::tcols());
    int rows = static_cast<int>(rlutil::trows());

    LifeSimulator sim(cols, rows);
    RendererConsole pic;
    sim.insertPattern(PatternGosperGliderGun(), 20, 1);
    sim.insertPattern(PatternPulsar(), 100, 10);
    rlutil::cls();
    int yeah = 0;
    while (yeah < 10)
    {
        rlutil::hidecursor();
        pic.render(sim);
        rlutil::showcursor();
        sim.update();
        std::cout << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        yeah++;
    }
    return 0;
}
