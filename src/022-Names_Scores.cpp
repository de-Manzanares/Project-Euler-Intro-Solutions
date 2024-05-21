//  Solution 22 - Names Scores
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
//  https://projecteuler.net/problem=22

#include <fstream>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

// read into a vector

// warning - only works with capital letters
int letter_position(char ch)
{
    return abs(ch - 'A') + 1;
}

int score_name(int n, const std::string& name)
{
    int sum = 0;
    for (const auto& ch : name) {
        sum += letter_position(ch);
    }
    return n * sum;
}

int main()
{
    std::ifstream inFile("../data/022_names.txt");
    std::string name;
    std::vector<std::string> names;
    assert(inFile.is_open());

    // read names into vector
    while (std::getline(inFile, name, ',')) {
        name = name.substr(1, name.size() - 2);    // remove quotation marks
        names.push_back(name);
    }
    // sort into alphabetical order
    std::sort(names.begin(), names.end());
    int sumOfAllScores{};
    int multiplier = 1;
    for (const auto& name : names) {
        sumOfAllScores += score_name(multiplier++, name);
    }
    std::cout << sumOfAllScores;
}
