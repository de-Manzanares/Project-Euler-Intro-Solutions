//  Solution Base Class
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

#ifndef PROJECT_EULER_SOLUTIONS_SOLUTION_H
#define PROJECT_EULER_SOLUTIONS_SOLUTION_H

#include <iostream>
#include <memory>
#include "Solution_All.h"

class Solution {
public:
    void select(int number);
private:
    std::unique_ptr<Solution_001> ptr_001 = nullptr;
    std::unique_ptr<Solution_002> ptr_002 = nullptr;
    std::unique_ptr<Solution_003> ptr_003 = nullptr;
    std::unique_ptr<Solution_004> ptr_004 = nullptr;
    std::unique_ptr<Solution_005> ptr_005 = nullptr;
    std::unique_ptr<Solution_006> ptr_006 = nullptr;
    std::unique_ptr<Solution_007> ptr_007 = nullptr;
    std::unique_ptr<Solution_008> ptr_008 = nullptr;
    std::unique_ptr<Solution_009> ptr_009 = nullptr;
    std::unique_ptr<Solution_010> ptr_010 = nullptr;
    std::unique_ptr<Solution_011> ptr_011 = nullptr;
    std::unique_ptr<Solution_012> ptr_012 = nullptr;
};

void Solution::select(int number)
{
    switch (number) {
    case 1:
        ptr_001 = std::make_unique<Solution_001>();
        ptr_001->print_solution();
        break;
    case 2:
        ptr_002 = std::make_unique<Solution_002>();
        ptr_002->print_solution();
        break;
    case 3:
        ptr_003 = std::make_unique<Solution_003>();
        ptr_003->print_solution();
        break;
    case 4:
        ptr_004 = std::make_unique<Solution_004>();
        ptr_004->print_solution();
        break;
    case 5:
        ptr_005 = std::make_unique<Solution_005>();
        ptr_005->print_solution();
        break;
    case 6:
        ptr_006 = std::make_unique<Solution_006>();
        ptr_006->print_solution();
        break;
    case 7:
        ptr_007 = std::make_unique<Solution_007>();
        ptr_007->print_solution();
        break;
    case 8:
        ptr_008 = std::make_unique<Solution_008>();
        ptr_008->print_solution();
        break;
    case 9:
        ptr_009 = std::make_unique<Solution_009>();
        ptr_009->print_solution();
        break;
    case 10:
        ptr_010 = std::make_unique<Solution_010>();
        ptr_010->print_solution();
        break;
    case 11:
        ptr_011 = std::make_unique<Solution_011>();
        ptr_011->print_solution();
        break;
    case 12:
        ptr_012 = std::make_unique<Solution_012>();
        ptr_012->print_solution();
        break;
    default:
        std::cout << "\ninvalid solution number\n\n";
        break;
    }
}

#endif //PROJECT_EULER_SOLUTIONS_SOLUTION_H
