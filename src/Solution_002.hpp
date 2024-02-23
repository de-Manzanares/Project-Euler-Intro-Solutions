/// @file Solution_002.hpp
/// @brief Solution 2

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
 * https://projecteuler.net/problem=2
 */

#ifndef PROJECTEULERSOLUTIONS_SOLUTION_2_H
#define PROJECTEULERSOLUTIONS_SOLUTION_2_H

#include <vector>

class Solution_002 : public Solution<size_t> {
public:
    Solution_002();
    void prompt() override;
    void run_algorithm() override;
    enum class NumberType {
        even, odd, all
    };
private:
    size_t sum{};
    size_t ceiling = 4'000'000;
    NumberType selector{};
};

Solution_002::Solution_002() { path = "../data/problems/002.txt"; }

void Solution_002::prompt()
{
    std::string line;
    std::cout << "(e)ven, (o)dd, or (a)ll: ";
    std::getline(std::cin, line);
    if (!line.empty()) {
        if (line.find('e') != std::string::npos) {
            selector = NumberType::even;
        }
        else if (line.find('o') != std::string::npos) {
            selector = NumberType::odd;
        }
        else if (line.find('a') != std::string::npos) {
            selector = NumberType::all;
        }
    }

    std::cout << "Ceiling: ";
    std::getline(std::cin, line);
    if (!line.empty()) {
        ceiling = 0;
        std::string scrubbed_line;
        for (char c : line) {
            if (std::isdigit(c)) {
                scrubbed_line.push_back(c);
            }
        }
        std::stringstream ss(scrubbed_line);
        int num;
        ss >> num;
        if (num > 0) {
            ceiling = num;
        }
    }
    std::cout << "\nCalculating ... \n";
}

void Solution_002::run_algorithm()
{
    stopwatch.start();

    std::vector<int> fibonacciSequence = {1, 2};
    std::vector<int> selectNumbers{};

    for (int i = 0; fibonacciSequence.back() < ceiling; i++) {
        fibonacciSequence.push_back(
                fibonacciSequence[i] + fibonacciSequence[i + 1]);
    }
    if (fibonacciSequence.back() > ceiling) {
        fibonacciSequence.pop_back();
    }
    if (selector == NumberType::even) {
        for (auto i : fibonacciSequence) {
            if (i % 2 == 0) {
                selectNumbers.push_back(i);
            }
        }
    }
    else if (selector == NumberType::odd) {
        for (auto i : fibonacciSequence) {
            if (i % 2 != 0) {
                selectNumbers.push_back(i);
            }
        }
    }
    else if (selector == NumberType::all) {
        selectNumbers = fibonacciSequence;
    }
    for (auto i : selectNumbers) {
        sum += i;
    }
    solution = sum;

    stopwatch.stop();

    solution_string = insert_commas(solution);
}

#endif //PROJECTEULERSOLUTIONS_SOLUTION_2_H
