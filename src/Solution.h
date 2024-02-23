/// @file Solution.h
/// @brief Template for solutions

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

#ifndef SRC_SOLUTION_H_
#define SRC_SOLUTION_H_

#include <fstream>
#include <iostream>
#include <string>
#include "Stopwatch.h"
#include "util.h"

template<typename T>
class Solution {
public:
    virtual void run()
    {
        print_problem();
        prompt();
        run_algorithm();
        print_solution();
        print_stopwatch_readout();
    }

    void print_problem() const;
    virtual void prompt() = 0;
    virtual void run_algorithm() = 0;
    void print_solution() const;
    void print_stopwatch_readout();

protected:
    Stopwatch stopwatch;
    T solution{};
    std::string solution_string{};
    std::string path{};
};

template<typename T>
void Solution<T>::print_problem() const
{
    std::fstream file(path);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << "\n";
        }
    }
    else {
        std::cout << "file not opened";
    }
}

template<typename T>
void Solution<T>::print_solution() const
{
    std::cout <<
              "\n----------------------------------------\n" <<
              solution_string <<
              "\n----------------------------------------\n" <<
              "\n";
}

template<typename T>
void Solution<T>::print_stopwatch_readout()
{
    std::cout << "Algorithm execution time: \n";
    stopwatch.print_readout();
    stopwatch.print_readout_old();
}

#endif  // SRC_SOLUTION_H_
