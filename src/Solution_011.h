// Solution 11
// Copyright (c) 2024. de-Manzanares
// Contact: git.in.touch@dmanz.org
//
//     This program is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     This program is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
//
//     You should have received a copy of the GNU General Public License
//     along with this program.  If not, see <https://www.gnu.org/licenses/>.
//
// https://projecteuler.net/problem=11
//
#ifndef PROJECT_EULER_SOLUTIONS_SOLUTION_011_H
#define PROJECT_EULER_SOLUTIONS_SOLUTION_011_H

#include <fstream>

// TODO we can implement something similar to the fast product in solution 8

class Solution_011 {
public:
    static void print_solution()
    {
        read_grid();
        check_right();
        check_down();
    }

    static void read_grid();
    static void check_max(int comparator);
    static void check_right();
    static void check_down();

private:
    static bool DEV;
    static int RANGE;
    static int GRID[20][20];
    static int greatestProduct;
    static int max;

};

using s11 = Solution_011;

bool s11::DEV = true;
int s11::RANGE = 4;
int s11::GRID[20][20]{};
int s11::greatestProduct = 0;
int s11::max;

void s11::read_grid()
{
    for (auto& i : GRID) {
        for (int j = 0; j < 20; j++) {
            std::cin >> i[j];
            if (DEV) {
                std::cout << i[j] << " ";
                if (j != 0 && j % 19 == 0) {
                    std::cout << "\n";

                }
            }
        }
    }
}

void s11::check_max(int comparator)
{
    if (comparator > max) {
        max = comparator;
    }
}

void s11::check_right()
{
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 20 - (RANGE) + 1; j++) {
            int temporary_product = 1;
            for (int k = 0; k < RANGE; k++) {
                temporary_product *= GRID[i][j + k];
                if (DEV) {
                    std::cout << "\nDigits: " << GRID[i][j + k];

                }
            }
            check_max(temporary_product);
            if (DEV) {
                std::cout << "\nTemp product: " << temporary_product << "\n";
            }
        }
    }
}

void s11::check_down()
{

}

#endif //PROJECT_EULER_SOLUTIONS_SOLUTION_011_H
