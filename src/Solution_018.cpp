//  Solution 18
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
//  https://projecteuler.net/problem=18

#include <string>
#include <iostream>
#include <vector>
#include "Stopwatch.hpp"

class Number_Triangle {
public:
    void read_into_array(std::string string);
    void print_number_triangle();

    static int size() { return SIZE; }

    static const int SIZE = 15;
    int n[SIZE][SIZE]{};
};

void Number_Triangle::read_into_array(std::string string)
{
    int line_count = 0;
    int element_count = 0;
    std::string temp;

    for (const auto& ch : string) {
        if (ch == '\n') {
            if (!temp.empty()) {
                n[line_count][element_count] = std::stoi(temp);
                temp.clear();
            }
            line_count++;
            element_count = 0;
        }
        else if (std::isdigit(ch)) {
            temp += ch;
        }
        else if (ch == ' ' && !temp.empty()) {
            n[line_count][element_count] = std::stoi(temp);
            temp.clear();
            element_count++;
        }
    }
}

void Number_Triangle::print_number_triangle()
{
    for (int l = 0; l < size(); l++) {
        for (int e = 0; e < size(); e++) {
            std::cout << n[l][e] << " ";
        }
        std::cout << "\n";
    }
}

struct Path {
    Path();
    std::vector<Path> spawn_paths(std::vector<Path>& paths);
    std::vector<int> steps;
    int sum;
};

Path::Path()
{
    steps.push_back(0);
    sum = 0;
}

std::vector<Path> Path::spawn_paths(std::vector<Path>& paths)
{
    std::vector<Path> temp{};
    for (auto& path : paths) {
        // left
        Path left(path);
        left.steps.push_back(path.steps.back());
        // right
        Path right(path);
        right.steps.push_back(path.steps.back() + 1);
        // populate vector
        temp.push_back(left);
        temp.push_back(right);
    }
    return temp;
}

struct Path_Tree {
    int max_path_number{};
    int max_path_sum{};
    Path start;
    std::vector<Path> paths{start};
    Number_Triangle triangle;
    void calculate_sum(Path& p, Number_Triangle t);
};

void Path_Tree::calculate_sum(Path& p, Number_Triangle t)
{
    p.sum = 0;
    for (int i = 0; i < p.steps.size(); i++) {
        p.sum += t.n[i][p.steps[i]];
    }
    if (p.sum > max_path_sum) {
        max_path_sum = p.sum;
    }
}

int main()
{
    Stopwatch stopwatch;
    Path_Tree pt;
    std::string triangle_text =
            "75                                          '\n'"
            "95 64                                       '\n'"
            "17 47 82                                    '\n'"
            "18 35 87 10                                 '\n'"
            "20 04 82 47 65                              '\n'"
            "19 01 23 75 03 34                           '\n'"
            "88 02 77 73 07 63 67                        '\n'"
            "99 65 04 28 06 16 70 92                     '\n'"
            "41 41 26 56 83 40 80 70 33                  '\n'"
            "41 48 72 33 47 32 37 16 94 29               '\n'"
            "53 71 44 65 25 43 91 52 97 51 14            '\n'"
            "70 11 33 28 77 73 17 78 39 68 17 57         '\n'"
            "91 71 52 38 17 14 91 43 58 50 27 29 48      '\n'"
            "63 66 04 68 89 53 67 30 73 16 69 87 40 31   '\n'"
            "04 62 98 27 23 09 70 98 73 93 38 53 60 04 23'\n'";

    pt.triangle.read_into_array(triangle_text);
    stopwatch.start();
    for (int i = 0; i < 14; i++) {
        pt.paths = pt.start.spawn_paths(pt.paths);
        for (auto& path : pt.paths) {
            pt.calculate_sum(path, pt.triangle);
        }
    }
    stopwatch.stop();
    std::cout << "Max Path: ";  // not implemented
    std::cout << "\nMax path sum: " << pt.max_path_sum << "\n\n";
    stopwatch.print_readout();

    return 0;
}

// other people were using a bottom up approach ...
// that may be the way to go about it for problem 67
