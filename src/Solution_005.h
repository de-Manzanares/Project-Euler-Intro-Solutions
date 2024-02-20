/*
 * Solution 5
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
 * https://projecteuler.net/problem=5
 */

#ifndef PROJECTEULERSOLUTIONS_SOLUTION_5_H
#define PROJECTEULERSOLUTIONS_SOLUTION_5_H

#include <cstddef>
#include <cmath>

class Solution_005 {
public:
    void print_solution()
    {
        Stopwatch stopwatch;
        stopwatch.start();
        bool found = false;
        bool failed;
        int j;

        for (size_t i = (20 * 19);
             i < static_cast<size_t>(pow(2, 64)) && !found;
             i++) {
            failed = false;
            j = 20;
            while (!found && !failed && j > 0) {
                if (i % j != 0) {
                    failed = true;
                }
                j--;
                if (j == 1 && !failed) {
                    found = true;
                }
            }
            if (found) {
                std::cout << i << std::endl;
            }
        }
        stopwatch.stop();
    }
};

#endif //PROJECTEULERSOLUTIONS_SOLUTION_5_H
