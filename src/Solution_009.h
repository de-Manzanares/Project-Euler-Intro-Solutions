/*
 * Solution 9
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
 * https://projecteuler.net/problem=9
 */

#ifndef PROJECTEULERSOLUTIONS_SOLUTION_9_H
#define PROJECTEULERSOLUTIONS_SOLUTION_9_H

#include <iostream>

class Solution_009 {
public:
    static void print_solution()
    {
        // check all the ways 3 numbers can sum to 1000
        // check if a^2+b^2=c^2
        int SUM = 1000;
        int b;
        int c;
        int j = 0;

        for (int a = 1; a <= SUM - 2; a++) {
            b = 1;
            c = SUM - (a + b);
            for (int i = 0; i < (SUM - (2 + j)); i++) {
                // std::cout << "a = " << a << "\tb = " << b << "\tc = " << c <<
                //           "\tsum = " << a+b+c << std::endl;
                if (a * a + b * b == c * c) {
                    std::cout << "Pythagorean triplet found: "
                              << "a = " << a << "\tb = " << b << "\tc = " << c
                              << std::endl;
                    std::cout << "Product `abc` = " << a * b * c << std::endl;
                }
                b += 1;
                c -= 1;
            }
            j++;
        }
    }
};

#endif //PROJECTEULERSOLUTIONS_SOLUTION_9_H
