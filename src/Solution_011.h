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

#define DEBUG

#include <fstream>

// TODO we can implement something similar to the fast product in solution 8
// TODO fix stopwatch placement
// TODO fix coordinate printing

class Solution_011 {
public:
    static void print_solution()
    {
        read_grid();
        check_right();                  // direction 0
        check_down();                   // direction 1
        check_diagonal_down_right();    // direction 2
        check_diagonal_down_left();     // direction 3
        print_report();
    }

    static void read_grid();
    static void check_max(int comparator);
    static void check_right();
    static void check_down();
    static void check_diagonal_down_right();
    static void check_diagonal_down_left();
    static void print_report();

private:
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
#ifdef DEBUG
            std::cout << i[j] << " ";
            if (j != 0 && j % 19 == 0) {
                std::cout << "\n";
            }
#endif
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
        for (column = 0; column < (20 - RANGE + 1); column++) {
            int temporary_product = 1;
#ifdef DEBUG
            std::cout << std::setw(15) << std::left << "Check: RIGHT"
                      << "row = " << std::setw(6) << row + 1
                      << "column = " << std::setw(6) << column + 1
                      << "Factors: ";
#endif
            for (int k = 0; k < RANGE; k++) {
                temporary_product *= GRID[row][column + k];
#ifdef DEBUG
                std::cout << GRID[row][column + k] << ", ";
#endif
            }
            check_max(temporary_product);
#ifdef DEBUG
            std::cout << "\tTemp product: " << temporary_product << "\n";
#endif
        }
    }
}

void s11::check_down()
{
    direction_checking = 1;
    for (row = 0; row < (20 - RANGE + 1); row++) {
        for (column = 0; column < 20; column++) {
            int temporary_product = 1;
#ifdef DEBUG
            std::cout << std::setw(15) << std::left << "Check: DOWN"
                      << "row = " << std::setw(6) << row + 1
                      << "column = " << std::setw(6) << column + 1
                      << "Factors: ";
#endif
            for (int k = 0; k < RANGE; k++) {
                temporary_product *= GRID[row + k][column];
#ifdef DEBUG
                std::cout << GRID[row + k][column] << ", ";
#endif
            }
            check_max(temporary_product);
#ifdef DEBUG
            std::cout << "\tTemp product: " << temporary_product << "\n";
#endif
        }
    }
}

void s11::check_diagonal_down_right()
{
    direction_checking = 2;
    for (row = 0; row < (20 - RANGE + 1); row++) {
        for (column = 0; column < (20 - RANGE + 1); column++) {
            int temporary_product = 1;
#ifdef DEBUG
            std::cout << std::setw(25) << std::left << "Check: D - DOWN RIGHT"
                      << "row = " << std::setw(6) << row + 1
                      << "column = " << std::setw(6) << column + 1
                      << "Factors: ";
#endif
            for (int k = 0; k < RANGE; k++) {
                temporary_product *= GRID[row + k][column + k];
#ifdef DEBUG
                std::cout << GRID[row + k][column + k] << ", ";
#endif
            }
            check_max(temporary_product);
#ifdef DEBUG
            std::cout << "\tTemp product: " << temporary_product << "\n";
#endif
        }
    }
}

void s11::check_diagonal_down_left()
{
    direction_checking = 3;
    for (row = 0; row < (20 - RANGE + 1); row++) {
        for (column = RANGE - 1; column < 20; column++) {
            int temporary_product = 1;
#ifdef DEBUG
            std::cout << std::setw(25) << std::left << "Check: D - DOWN LEFT"
                      << "row = " << std::setw(6) << row + 1
                      << "column = " << std::setw(6) << column + 1
                      << "Factors: ";
#endif
            for (int k = 0; k < RANGE; k++) {
                temporary_product *= GRID[row + k][column - k];
#ifdef DEBUG
                std::cout << GRID[row + k][column - k] << ", ";
#endif
            }
            check_max(temporary_product);
#ifdef DEBUG
            std::cout << "\tTemp product: " << temporary_product << "\n";
#endif
        }
    }
}

void s11::print_report()
{
    std::cout << "\nMax product = " << max
              << "\nLocation: Row " << (max_location[0] + 1) << ", "
              << "Column " << (max_location[1] + 1)
              << "\nDirection: ";

    switch (direction_found) {
    case 0:
        std::cout << "Right";
        break;
    case 1:
        std::cout << "Down";
        break;
    case 2:
        std::cout << "Diagonal Down Right";
        break;
    case 3:
        std::cout << "Diagonal Down Left";
        break;
    default:
        std::cout << "\ninvalid direction\n";
    }

    std::cout << "\nFactors: ";

    switch (direction_found) {
    case 0:
        for (int i = 0; i < RANGE; i++) {
            std::cout << GRID[max_location[0]][max_location[1] + i] << ", ";
        }
        break;
    case 1:
        for (int i = 0; i < RANGE; i++) {
            std::cout << GRID[max_location[0] + i][max_location[1]] << ", ";
        }
        break;
    case 2:
        for (int i = 0; i < RANGE; i++) {
            std::cout << GRID[max_location[0] + i][max_location[1] + i] << ", ";
        }
        break;
    case 3:
        for (int i = 0; i < RANGE; i++) {
            std::cout << GRID[max_location[0] + i][max_location[1] - i] << ", ";
        }
        break;
    default:
        std::cout << "\ninvalid direction\n";
    }
    std::cout << "\n\n";
}

#endif //PROJECT_EULER_SOLUTIONS_SOLUTION_011_H
