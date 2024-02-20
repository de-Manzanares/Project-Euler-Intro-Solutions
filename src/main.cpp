#include "Solution.h"

// TODO solution prompts and explanations

int main()
{
    int input = -1;
    Solution s;

    while (input != 0) {
        std::cout << "\nEnter a solution number or '0' to exit:\n";
        std::cin >> input;
        s.select(input);
    }
    return 0;
}
