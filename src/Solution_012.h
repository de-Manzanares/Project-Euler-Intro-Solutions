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

// TODO terribly inefficient ... 27 minutes!!!

#ifndef PROJECT_EULER_SOLUTIONS_SOLUTION_012_H
#define PROJECT_EULER_SOLUTIONS_SOLUTION_012_H

class Solution_012 {
public:
    void print_factor_list();

    void print_solution()
    {
        while (!numberFound && iterator < SIZE_MAX) {
            generate_triangle_number();
            count_factors();
            print_progress();
        }
        if (numberFound) {
            std::cout << "\n\nFirst triangle number with over "
                      << REQ_DIVISORS << " factors: " << triangleNumber
                      << "\n\n";
            print_factor_list();
        }
        else {
            std::cout << "Something went wrong\n\n";
        }
    }

    void generate_triangle_number();
    void count_factors();
    void print_progress();

private:
    size_t REQ_DIVISORS = 500;
    size_t iterator = 2;
    int progressTracker = 1;
    size_t previousTriangleNumber = 1;
    size_t triangleNumber{};
    bool numberFound = false;
    std::vector<size_t> divisorList{};
    int maxDivisorCount{};
    std::vector<size_t> maxDivisorList{};
};

using S12 = Solution_012;

void S12::generate_triangle_number()
{
    triangleNumber = previousTriangleNumber + (iterator++);
    previousTriangleNumber = triangleNumber;
}

void S12::count_factors()
{
    divisorList.clear();
    divisorList.push_back(1);
    divisorList.push_back(triangleNumber);
    for (size_t i = 2; i < (triangleNumber/2)+1; i++) {
        if (triangleNumber % i == 0) {
            divisorList.push_back(i);
        }
    }
    if (divisorList.size() > maxDivisorCount) {
        maxDivisorCount = divisorList.size();
    }
    if (divisorList.size() > REQ_DIVISORS) {
        maxDivisorList = divisorList;
        numberFound = true;
    }
}

void Solution_012::print_progress()
{
    if (iterator % 100 == 0) {
        std::cout << (100 * progressTracker++) << " triangle numbers checked";
        std::cout << "\tMax factor list size: " << maxDivisorCount << "\n";
        maxDivisorCount = 2;
    }
}

void Solution_012::print_factor_list()
{
    std::sort(maxDivisorList.begin(), maxDivisorList.end());
    for (int i = 0; i < maxDivisorList.size(); i++) {
        std::cout << maxDivisorList[i] << ", ";
    }
    std::cout << "\n\n";
}

#endif  // PROJECT_EULER_SOLUTIONS_SOLUTION_012_H
