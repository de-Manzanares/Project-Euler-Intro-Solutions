/// @file Solution_003.hpp
/// @brief Solution 3

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
 * https://projecteuler.net/problem=3
 */

//

#ifndef PROJECTEULERSOLUTIONS_SOLUTION_3_H
#define PROJECTEULERSOLUTIONS_SOLUTION_3_H

#include <cstddef>
#include <iostream>

class Solution_003 : public Solution<size_t> {
public:
    Solution_003();
    void prompt() override;
    void run_algorithm() override;

private:
    void generate_100_more_primes();
    size_t target_number = 600'851'475'143;
    std::vector<size_t> primes{2};
    size_t index{};
};

Solution_003::Solution_003()
{
    path = "../data/problems/003.txt";
}

void Solution_003::prompt()
{
    std::cout << "Number: ";
    std::string line;
    std::getline(std::cin, line);
    if (!line.empty()) {
        target_number = 0;
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
            target_number = num;
        }
    }
    std::cout << "\nCalculating ... \n";
}

void Solution_003::run_algorithm()
{
    stopwatch.start();

    size_t largestPrime;
    bool primeNotFound = true;

    while (primeNotFound) {
        while (index < primes.size()) {
            while (!(target_number % primes[index])) {
                target_number /= primes[index];
                largestPrime = primes[index];
            }
            if (target_number == 1) {
                primeNotFound = false;
            }
            index++;
        }
        if (primeNotFound) {
            generate_100_more_primes();
        }
    }

    solution = largestPrime;

    stopwatch.stop();

    solution_string = insert_commas(solution);
}

void Solution_003::generate_100_more_primes()
{
    bool hasPrimeFactor;
    bool provenComposite;
    size_t pushbacks = 0;
    for (size_t number = primes.back() + 1; pushbacks < 100; number++) {
        provenComposite = false;
        for (size_t i = 0; i < primes.size() && !provenComposite; i++) {
            hasPrimeFactor = (number % primes[i] == 0);
            if (hasPrimeFactor) {
                provenComposite = true;
            }
        }
        if (!provenComposite) {
            primes.push_back(number);
            pushbacks++;
        }
    }
}

#endif //PROJECTEULERSOLUTIONS_SOLUTION_3_H
