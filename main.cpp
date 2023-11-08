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
    std::uint8_t cols = static_cast<std::uint8_t>(rlutil::tcols());
    std::uint8_t rows = static_cast<std::uint8_t>(rlutil::trows());

    LifeSimulator sim(cols, rows);
    RendererConsole pic;
    sim.insertPattern(PatternGosperGliderGun(), 20, 1);
    sim.insertPattern(PatternPulsar(), 100, 10);
    sim.insertPattern(PatternBlinker(), 50, 10);
    sim.insertPattern(PatternBlock(), 5, 25);
    rlutil::cls();

    while (true)
    {
        rlutil::hidecursor();
        pic.render(sim);
        sim.update();
        std::cout << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    return 0;
}
