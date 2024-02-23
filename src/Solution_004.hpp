/*
 * Solution 4
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
 * https://projecteuler.net/problem=4
 */

#ifndef PROJECTEULERSOLUTIONS_SOLUTION_4_H
#define PROJECTEULERSOLUTIONS_SOLUTION_4_H

#include <iostream>
#include <string>

bool checkPalindrome(int x);

class Solution_004 {
public:
    void print_message()
    {
        std::cout
                << "A palindromic number reads the same both ways. The "
                   "largest palindrome made from the product of two 2-digit "
                   "numbers is 9009 = 91 × 99.\n"
                << "Find the largest palindrome made from the product of two "
                   "3-digit numbers.\n";
    }

    void print_solution()
    {
        print_message();
        Stopwatch stopwatch;
        stopwatch.start();
        std::vector<int> palindromes;
        int temporaryPalindrome;
        int maxPalindrome;

        for (int i = 999; i > 99; i--) {
            if (i % 11 == 0) {
                for (int j = 999; j > 99; j--) {
                    if (checkPalindrome(i * j)
                            && (temporaryPalindrome = i * j) > maxPalindrome) {
                        maxPalindrome = temporaryPalindrome;
                    }
                }
            }
        }
        std::cout << maxPalindrome << std::endl;
        stopwatch.stop();
    }
};

bool checkPalindrome(int x)
{
    std::string str_x = std::to_string(x);
    int front = 0;
    int back = static_cast<int>(str_x.size() - 1);
    bool provenFalse = false;
    int i = 0;

    while (!provenFalse && i < (str_x.size() / 2 + str_x.size() % 2)) {
        if (str_x[front + i] != str_x[back - i]) {
            provenFalse = true;
        }
        i++;
    }
    return !provenFalse;
}

#endif //PROJECTEULERSOLUTIONS_SOLUTION_4_H
