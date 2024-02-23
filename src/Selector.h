/// @file Selector.h
/// @brief Selects which subprogram to run

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

#ifndef SRC_SELECTOR_H_
#define SRC_SELECTOR_H_

#include <iostream>
#include <limits>
#include <memory>
#include "Solution_All.h"

class Selector {
public:
    static bool keep_goin;
    static void select();
private:
    static std::unique_ptr<Solution_001> ptr_001;
    static std::unique_ptr<Solution_002> ptr_002;
    static std::unique_ptr<Solution_003> ptr_003;
    static std::unique_ptr<Solution_004> ptr_004;
    static std::unique_ptr<Solution_005> ptr_005;
    static std::unique_ptr<Solution_006> ptr_006;
    static std::unique_ptr<Solution_007> ptr_007;
    static std::unique_ptr<Solution_008> ptr_008;
    static std::unique_ptr<Solution_009> ptr_009;
    static std::unique_ptr<Solution_010> ptr_010;
    static std::unique_ptr<Solution_011> ptr_011;
    static std::unique_ptr<Solution_012> ptr_012;
};

bool Selector::keep_goin = true;
std::unique_ptr<Solution_001> Selector::ptr_001 = nullptr;
std::unique_ptr<Solution_002> Selector::ptr_002 = nullptr;
std::unique_ptr<Solution_003> Selector::ptr_003 = nullptr;
std::unique_ptr<Solution_004> Selector::ptr_004 = nullptr;
std::unique_ptr<Solution_005> Selector::ptr_005 = nullptr;
std::unique_ptr<Solution_006> Selector::ptr_006 = nullptr;
std::unique_ptr<Solution_007> Selector::ptr_007 = nullptr;
std::unique_ptr<Solution_008> Selector::ptr_008 = nullptr;
std::unique_ptr<Solution_009> Selector::ptr_009 = nullptr;
std::unique_ptr<Solution_010> Selector::ptr_010 = nullptr;
std::unique_ptr<Solution_011> Selector::ptr_011 = nullptr;
std::unique_ptr<Solution_012> Selector::ptr_012 = nullptr;

void Selector::select()
{
    int number;
    std::cout << "\nEnter a problem number or '0' to quit\n";
    std::cin >> number;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch (number) {
    case 0:
        std::cout << "\nThanks for stopping by\n";
        keep_goin = false;
        break;
    case 1:
        ptr_001 = std::make_unique<Solution_001>();
        ptr_001->run();
        ptr_001.reset();
        break;
    case 2:
        // ptr_002 = std::make_unique<Solution_002>();
        // ptr_002->print_solution();
        // ptr_002.reset();
        std::cout << "\nCLI not yet implemented, see source for solution\n\n";
        break;
    case 3:
        // ptr_003 = std::make_unique<Solution_003>();
        // ptr_003->print_solution();
        // ptr_003.reset();
        std::cout << "\nCLI not yet implemented, see source for solution\n\n";
        break;
    case 4:
        // ptr_004 = std::make_unique<Solution_004>();
        // ptr_004->print_solution();
        // ptr_004.reset();
        std::cout << "\nCLI not yet implemented, see source for solution\n\n";
        break;
    case 5:
        // ptr_005 = std::make_unique<Solution_005>();
        // ptr_005->print_solution();
        // ptr_005.reset();
        std::cout << "\nCLI not yet implemented, see source for solution\n\n";
        break;
    case 6:
        // ptr_006 = std::make_unique<Solution_006>();
        // ptr_006->print_solution();
        // ptr_006.reset();
        std::cout << "\nCLI not yet implemented, see source for solution\n\n";
        break;
    case 7:
        // ptr_007 = std::make_unique<Solution_007>();
        // ptr_007->print_solution();
        // ptr_007.reset();
        std::cout << "\nCLI not yet implemented, see source for solution\n\n";
        break;
    case 8:
        // ptr_008 = std::make_unique<Solution_008>();
        // ptr_008->print_solution();
        // ptr_008.reset();
        std::cout << "\nCLI not yet implemented, see source for solution\n\n";
        break;
    case 9:
        // ptr_009 = std::make_unique<Solution_009>();
        // ptr_009->print_solution();
        // ptr_009.reset();
        std::cout << "\nCLI not yet implemented, see source for solution\n\n";
        break;
    case 10:
        // ptr_010 = std::make_unique<Solution_010>();
        // ptr_010->print_solution();
        // ptr_010.reset();
        std::cout << "\nCLI not yet implemented, see source for solution\n\n";
        break;
    case 11:
        // ptr_011 = std::make_unique<Solution_011>();
        // ptr_011->print_solution();
        // ptr_011.reset();
        std::cout << "\nCLI not yet implemented, see source for solution\n\n";
        break;
    case 12:
        // ptr_012 = std::make_unique<Solution_012>();
        // ptr_012->print_solution();
        // ptr_012.reset();
        std::cout << "\nCLI not yet implemented, see source for solution\n\n";
        break;
    default:
        if (number > 0 && number <= 100) {
            std::cout << "\nHaven't solved that one yet!\n\n";
        }
        else {
            std::cout << "\nProblem range: [1,100]\n\n";
        }
        break;
    }
}

#endif  // SRC_SELECTOR_H_
