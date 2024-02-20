//  Solution 12
//  Copyright (c) 2024. de-Manzanares
//  Contact: git.in.touch@dmanz.org
//
//      This program is free software: you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation, either version 3 of the License, or
//      (at your option) any later version.
//
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//
//      You should have received a copy of the GNU General Public License
//      along with this program.  If not, see <https://www.gnu.org/licenses/>.
//
//  https://projecteuler.net/problem=12

// TODO I bet there's some corners we can cut ...

#ifndef PROJECT_EULER_SOLUTIONS_SOLUTION_012_H
#define PROJECT_EULER_SOLUTIONS_SOLUTION_012_H

#include "Stopwatch.h"
#include <cmath>
#include <algorithm>

class Solution_012 {
public:
    void print_divisor_list();

    void print_solution()
    {
        Stopwatch stopwatch;
        stopwatch.start();

        while (!numberFound && iterator < SIZE_MAX) {
            generate_triangle_number();
            count_factors();
            print_progress();
        }
        std::cout << "\n\nFirst triangle number with over "
                  << REQ_DIVISORS << " divisors: " << triangleNumber
                  << "\n\n";
        print_divisor_list();

        stopwatch.stop();
    }

    void generate_triangle_number();
    void count_factors();
    void print_progress();

private:
    u_int64_t REQ_DIVISORS = 500;
    u_int64_t iterator = 2;
    int progressTracker = 1;
    u_int64_t previousTriangleNumber = 1;
    u_int64_t triangleNumber{};
    bool numberFound = false;
    std::vector<u_int64_t> divisorList{};
    std::vector<u_int64_t> maxDivisorList{};
    int divisorCount{};
    int maxDivisorCount{};
};

using S12 = Solution_012;

void S12::generate_triangle_number()
{
    triangleNumber = previousTriangleNumber + (iterator++);
    previousTriangleNumber = triangleNumber;
}

void S12::count_factors()
{
    divisorCount = 2;
    for (u_int64_t i = 2;
         static_cast<double>(i) < sqrt(static_cast<double>(triangleNumber)) + 1;
         i++) {
        if (triangleNumber % i == 0) {
            divisorCount += 2;
        }
        if (i * i == triangleNumber) {
            divisorCount++;
        }
        if (divisorCount > maxDivisorCount) {
            maxDivisorCount = divisorCount;
        }
    }
    if (divisorCount > REQ_DIVISORS) {
        numberFound = true;
    }
}

void Solution_012::print_divisor_list()
{
    for (u_int64_t i = 1;
         static_cast<double>(i) < sqrt(static_cast<double>(triangleNumber)) + 1;
         i++) {
        if (triangleNumber % i == 0) {
            if (i * i == triangleNumber) {
                divisorList.push_back(i);
            }
            else {
                divisorList.push_back(i);
                divisorList.push_back(triangleNumber / i);
            }

        }
    }
    std::cout << "\n" << divisorList.size() << " divisors:\n";
    std::sort(divisorList.begin(), divisorList.end());
    for (u_int64_t i = 0; i < divisorList.size(); i++) {
        std::cout << divisorList[i] << ", ";
    }
    std::cout << "\n\n";
}

void Solution_012::print_progress()
{
    if (iterator % 1000 == 0) {
        std::cout << (1000 * progressTracker++) << " triangle numbers checked";
        std::cout << "\tMax factor list size: " << maxDivisorCount << "\n";
        maxDivisorCount = 2;
    }
}

#endif  // PROJECT_EULER_SOLUTIONS_SOLUTION_012_H
