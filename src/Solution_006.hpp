/*
 * Solution 6
 * Copyright (c) 2024. de-Manzanares
 * Contact: git.in.touch@dmanz.org
 *
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * https://projecteuler.net/problem=6
 */

#ifndef PROJECTEULERSOLUTIONS_SOLUTION_6_H
#define PROJECTEULERSOLUTIONS_SOLUTION_6_H

#include <cmath>

class Solution_006 {
public:
    void print_message()
    {
        std::cout
                << "The sum of the squares of the first ten natural numbers "
                   "is,\n1^2 + 2^2 + ... + 10^2 = 385\n"
                   "The square of the sum of the first ten natural numbers "
                   "is,\n(1 + 2 + ... + 10)^2 = 55^2 = 3025\n"
                   "Hence the difference between the sum of the squares of "
                   "the first ten natural numbers and the square of the sum "
                   "is \n3025 − 385 = 2640.\n"
                   "Find the difference between the sum of the squares and "
                   "the square of the sums of the first one hundred natural "
                   "numbers.\n";
    }

    void print_solution()
    {
        Stopwatch stopwatch;
        print_message();
        stopwatch.start();
        size_t squareOfSum = 0;
        size_t sumOfSquares = 0;
        for (size_t i = 1; i <= 100; i++) {
            squareOfSum += i;
            sumOfSquares += static_cast<size_t>(pow(static_cast<double>(i), 2));
        }
        squareOfSum = static_cast<size_t>(
                pow(static_cast<double>(squareOfSum), 2));

        std::cout << squareOfSum - sumOfSquares << std::endl;
        stopwatch.stop();
    }
};

#endif //PROJECTEULERSOLUTIONS_SOLUTION_6_H
