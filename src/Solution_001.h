/*
 * Solution 1
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
 * https://projecteuler.net/problem=1
 */

#ifndef PROJECTEULERSOLUTIONS_SOLUTION_1_H
#define PROJECTEULERSOLUTIONS_SOLUTION_1_H

#include <iostream>
#include <vector>
#include <algorithm>

class Solution_001 {
public:
    static void print_solution(std::vector<int> number, int limit)
    {
        std::vector<int> multiples;
        int sum = 0;
        for (int i = 0; i < number.size(); i++) {
            for (int j = 1; number[i] * j < limit; j++) {
                multiples.push_back(number[i] * j);
            }
        }
        for (int i = 0; i < multiples.size(); i++) {
            std::sort(multiples.begin(), multiples.end());
            multiples.erase(
                    std::unique(multiples.begin(), multiples.end()),
                    multiples.end());
        }
        for (int i = 0; i < multiples.size(); i++) {
            sum += multiples[i];
        }
        std::cout << sum << std::endl;
    }
};

#endif //PROJECTEULERSOLUTIONS_SOLUTION_1_H