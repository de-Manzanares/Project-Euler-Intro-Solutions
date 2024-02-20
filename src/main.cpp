#include "Solution_All.h"

int main()
{
    Stopwatch stopwatch;
    std::unique_ptr<Solution_012> s12 = std::make_unique<Solution_012>();
    stopwatch.start();
    s12->print_solution();
    stopwatch.stop();
    return 0;
}
