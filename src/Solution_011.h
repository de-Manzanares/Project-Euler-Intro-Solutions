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
// TODO fix stopwatch placement
// TODO fix coordinate printing

class Solution_011 {
public:
    static void print_solution()
    {
        read_grid();
        check_right();      // direction 0
        check_down();       // direction 1
        print_report();
    }

    static void read_file_name();
    static void read_grid();
    static void check_max(int comparator);
    static void check_right();
    static void check_down();
    static void print_report();

private:
    static bool DEV;
    static int RANGE;
    static int GRID[20][20];
    static int row;
    static int column;
    static int max_location[2];
    static int max;
    static int direction_found;
    static int direction_checking;
};

using s11 = Solution_011;

bool s11::DEV = false;
int s11::RANGE = 4;
int s11::GRID[20][20];
int s11::row;
int s11::column;
int s11::max;
int s11::max_location[2];
int s11::direction_found{};
int s11::direction_checking{};

void s11::read_grid()
{
    for (auto& i: GRID) {
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
        max_location[0] = row;
        max_location[1] = column;
        direction_found = direction_checking;
    }
}

void s11::check_right()
{
    direction_checking = 0;
    for (row = 0; row < 20; row++) {
        for (column = 0; column < 20 - (RANGE) + 1; column++) {
            int temporary_product = 1;
            if (DEV) {
                std::cout << "Check: RIGHT"
                             "\ti = " << row << "\tcolumn = " << column
                          << "\nFactors: ";
            }
            for (int k = 0; k < RANGE; k++) {
                temporary_product *= GRID[row][column + k];
                if (DEV) {
                    std::cout << GRID[row][column + k] << ", ";
                }
            }
            check_max(temporary_product);
            if (DEV) {
                std::cout << "\nTemp product: " << temporary_product << "\n\n";
            }
        }
    }
}

void s11::check_down()
{

}

void s11::print_report()
{
    std::cout << "\nMax product = " << max
              << "\nLocation: (" << max_location[0] << " , " << max_location[1]
              << ")"
              << "\nDirection: ";

    switch (direction_found) {
    case 0:
        std::cout << "Right";
        break;
    case 1:
        std::cout << "Down";
        break;
    default:
        std::cout << "\ninvalid direction\n";
    }
    std::cout << "\nFactors: ";

    switch (direction_found) {
    case 0:
        for (int j = 0; j < RANGE; j++) {
            std::cout << GRID[max_location[0]][max_location[1] + j] << ", ";
        }
        break;
    default:
        std::cout << "\ninvalid direction\n";
    }
    std::cout << "\n\n";
}

#endif //PROJECT_EULER_SOLUTIONS_SOLUTION_011_H
