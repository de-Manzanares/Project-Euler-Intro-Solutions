/// @file Solution_001.hpp
/// @brief Solution 1

/* Copyright (c) 2024. de-Manzanares
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

#ifndef SRC_SOLUTION_001_H_
#define SRC_SOLUTION_001_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "Solution.hpp"

class Solution_001 : public Solution<int> {
public:
    Solution_001();
    void prompt() override;
    void run_algorithm() override;
private:
    std::vector<int> number = {3, 5};
    int limit = 1000;
};

Solution_001::Solution_001() { path = "../data/problems/001.txt"; }

void Solution_001::prompt()
{
    std::string line;
    std::cout << "Multiples of: ";
    std::getline(std::cin, line);
    if (!line.empty()) {
        number.clear();
        std::string scrubbed_line;
        for (char c : line) {
            if (std::isdigit(c) || c == ' ') {
                scrubbed_line.push_back(c);
            }
            else if (c == ',') {
                scrubbed_line.push_back(' ');
            }
        }
        std::stringstream ss(scrubbed_line);
        size_t num;
        while (ss) {
            ss >> num;
            if (num > 0) {
                number.push_back(num);
            }
        }
    }
    std::cout << "Limit: ";
    std::getline(std::cin, line);
    if (!line.empty()) {
        limit = 0;
        std::string scrubbed_line;
        for (char c : line) {
            if (std::isdigit(c)) {
                scrubbed_line.push_back(c);
            }
        }
        std::stringstream ss(scrubbed_line);
        size_t num{};
        ss >> num;
        if (num > 0) {
            limit = num;
        }
    }

    std::cout << "\nCalculating ... \n";
}

void Solution_001::run_algorithm()
{
    stopwatch.start();

    std::vector<int> multiples;

    int sum = 0;
    for (int i : number) {
        for (int j = 1; i * j < limit; j++) {
            multiples.push_back(i * j);
        }
    }
    for (int i = 0; i < multiples.size(); i++) {
        std::sort(multiples.begin(), multiples.end());
        multiples.erase(
                std::unique(multiples.begin(), multiples.end()),
                multiples.end());
    }
    for (int multiple : multiples) {
        sum += multiple;
        solution = sum;
    }

    stopwatch.stop();

    solution_string = insert_commas(static_cast<size_t>(solution));

}

#endif  // SRC_SOLUTION_001_H_
