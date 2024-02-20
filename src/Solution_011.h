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

#define VERBOSE

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

// TODO we can implement something similar to the fast product in solution 8
// TODO fix stopwatch placement
// TODO fix coordinate printing

class Solution_011 {
public:
    // BEGIN SOLUTION
    //--------------------------------------------------------------------------
    void print_solution()
    {
        Stopwatch stopwatch;;

        read_grid();

        stopwatch.start();

        check_down();
        check_right();
        check_down_right();
        check_down_left();
        print_report();

        stopwatch.stop();
    }
    // END SOLUTION
    //--------------------------------------------------------------------------

    enum class Direction {
        right, down, diagonalDownRight, diagonalDownLeft
    };

    // primary methods
    //---------------------------------------
    void read_grid();
    void check_right();
    void check_down();
    void check_down_right();
    void check_down_left();
    void print_report();

    // ancillary methods
    //---------------------------------------
    void check_max();
    std::string message_select(Direction direction);
    void print_factor_list(Direction direction, int p_row, int p_column);
#ifdef VERBOSE
    void print_calculations();
    void print_grid();
#endif

private:
    int RANGE = 4;
    int GRID[20][20]{};
    int row{};
    int column{};
    int max_location[2]{};
    int max{};
    Direction direction_found{};
    Direction direction_checking{};
    int temporaryProduct{};
};

using s11 = Solution_011;

// Method definitions
//--------------------------------------
void s11::read_grid()
{
    for (auto& i: GRID) {
        for (int& j: i) {
            std::cin >> j;
        }
    }
#ifdef VERBOSE
    print_grid();
#endif

}

void s11::check_right()
{
    direction_checking = Direction::right;
    for (row = 0; row < 20; row++) {
        for (column = 0; column < (20 - RANGE + 1); column++) {
            temporaryProduct = 1;
            for (int k = 0; k < RANGE; k++) {
                temporaryProduct *= GRID[row][column + k];
            }
            check_max();
#ifdef VERBOSE
            print_calculations();
#endif
        }
    }
}

void s11::check_down()
{
    direction_checking = Direction::down;
    for (row = 0; row < (20 - RANGE + 1); row++) {
        for (column = 0; column < 20; column++) {
            temporaryProduct = 1;
            for (int k = 0; k < RANGE; k++) {
                temporaryProduct *= GRID[row + k][column];
            }
            check_max();
#ifdef VERBOSE
            print_calculations();
#endif
        }
    }
}

void s11::check_down_right()
{
    direction_checking = Direction::diagonalDownRight;
    for (row = 0; row < (20 - RANGE + 1); row++) {
        for (column = 0; column < (20 - RANGE + 1); column++) {
            temporaryProduct = 1;
            for (int k = 0; k < RANGE; k++) {
                temporaryProduct *= GRID[row + k][column + k];
            }
            check_max();
#ifdef VERBOSE
            print_calculations();
#endif
        }
    }
}

void s11::check_down_left()
{
    direction_checking = Direction::diagonalDownLeft;
    for (row = 0; row < (20 - RANGE + 1); row++) {
        for (column = RANGE - 1; column < 20; column++) {
            temporaryProduct = 1;
            for (int k = 0; k < RANGE; k++) {
                temporaryProduct *= GRID[row + k][column - k];
            }
            check_max();
#ifdef VERBOSE
            print_calculations();
#endif
        }
    }
}

void s11::print_report()
{
    std::cout << "\nMax product = " << max
              << "\nLocation: Row "
              << (max_location[0] + 1) << ", "
              << "Column "
              << (max_location[1] + 1)
              << "\nDirection: " << message_select(direction_found)
              << "\nFactors: ";
    print_factor_list(direction_found, max_location[0], max_location[1]);
    std::cout << "\n\n";
}

void s11::check_max()
{
    if (temporaryProduct > max) {
        max = temporaryProduct;
        max_location[0] = row;
        max_location[1] = column;
        direction_found = direction_checking;
    }
}

std::string s11::message_select(Direction direction)
{
    std::string message;

    switch (direction) {
    case s11::Direction::right:
        message = "Right";
        break;
    case s11::Direction::down:
        message = "Down";
        break;
    case s11::Direction::diagonalDownRight:
        message = "Down Right";
        break;
    case s11::Direction::diagonalDownLeft:
        message = "Down Left";
        break;
    default:
        std::cout << "\ninvalid direction in print_calculations()\n";
    }
    return message;
}

void s11::print_factor_list(s11::Direction direction, int p_row, int p_column)
{
    switch (direction) {
    case Direction::right:
        for (int i = 0; i < RANGE; i++) {
            std::cout << std::setw(3) << GRID[p_row][p_column + i] << ", ";
        }
        break;
    case Direction::down:
        for (int i = 0; i < RANGE; i++) {
            std::cout << std::setw(3) << GRID[p_row + i][p_column] << ", ";
        }
        break;
    case Direction::diagonalDownRight:
        for (int i = 0; i < RANGE; i++) {
            std::cout << std::setw(3) << GRID[p_row + i][p_column + i] << ", ";
        }
        break;
    case Direction::diagonalDownLeft:
        for (int i = 0; i < RANGE; i++) {
            std::cout << std::setw(3) << GRID[p_row + i][p_column - i] << ", ";
        }
        break;
    }
}

#ifdef VERBOSE

void s11::print_calculations()
{
    std::cout << std::setw(15) << std::left
              << message_select(direction_checking)
              << "row = " << std::setw(6) << row + 1
              << "column = " << std::setw(6) << column + 1
              << "Factors: ";
    print_factor_list(direction_checking, row, column);
    std::cout << std::setw(10) << " ";
    std::cout << "Temp product: " << temporaryProduct << "\n";
}

void s11::print_grid()
{
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            std::cout << std::setw(3) << GRID[i][j];
            if (j != 0 && j % 19 == 0) {
                std::cout << "\n";
            }
        }
    }
}

#endif  // VERBOSE

#endif // PROJECT_EULER_SOLUTIONS_SOLUTION_011_H
