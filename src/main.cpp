#include "Solution_All.h"

int main()
{
    std::unique_ptr<Solution_012> s12 = std::make_unique<Solution_012>();
    s12->print_solution();
    return 0;
}
