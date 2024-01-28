#ifndef PROJECTEULERSOLUTIONS_SOLUTION_6_H
#define PROJECTEULERSOLUTIONS_SOLUTION_6_H

#include <cmath>

class Solution_6 {
public:
    static void print_solution()
    {
        //sum of the squares
        size_t sumOfSquares = 0;
        for (size_t i = 1; i<=100; i++) {
            sumOfSquares += static_cast<size_t>(pow(static_cast<double>(i), 2));
        }

        //square of the sums
        size_t squareOfSum = 0;
        for (size_t i = 1; i<=100; i++) {
            squareOfSum += i;
        }
        squareOfSum = static_cast<size_t>(
                pow(static_cast<double>(squareOfSum), 2));

        std::cout << squareOfSum-sumOfSquares << std::endl;
    }
};

#endif //PROJECTEULERSOLUTIONS_SOLUTION_6_H
