/*
 * Solution 2
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
 * https://projecteuler.net/problem=2
 */

#ifndef PROJECTEULERSOLUTIONS_SOLUTION_2_H
#define PROJECTEULERSOLUTIONS_SOLUTION_2_H

#include <vector>

class Solution_002 {
public:
    void print_message();

    void print_solution()
    {
        print_message();
        Stopwatch stopwatch;
        stopwatch.start();
        size_t sum = 0;
        std::vector<int> fibonacciSequence = {1, 2};
        std::vector<int> evenFibonacciNumbers;

        // Get Fibonacci sequence up to 4x10^6
        for (int i = 0; fibonacciSequence.back() < 4'000'000; i++) {
            fibonacciSequence.push_back(
                    fibonacciSequence[i] + fibonacciSequence[i + 1]);
        }
        if (fibonacciSequence.back() > 4'000'000) {
            fibonacciSequence.pop_back();
        }
        // Get even Fibonacci numbers
        for (int i: fibonacciSequence) {
            if (i % 2 == 0) {
                evenFibonacciNumbers.push_back(i);
            }
        }
        // Sum even Fibonacci numbers
        for (int evenFibonacciNumber: evenFibonacciNumbers) {
            sum += evenFibonacciNumber;
        }
        std::cout << sum << std::endl;
        stopwatch.stop();
    }
};

void Solution_002::print_message()
{
    std::cout << "Considering the terms in the Fibonacci sequence whose "
                 "values do not exceed four million, find the sum of the "
                 "even-valued terms.\n";
}

#endif //PROJECTEULERSOLUTIONS_SOLUTION_2_H
