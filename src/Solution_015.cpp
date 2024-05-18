//  Solution 15
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
//  https://projecteuler.net/problem=15

#include <iostream>
#include <vector>

class Mouse {
public:
    Mouse();
    explicit Mouse(int n);
    Mouse(int coord_x, int coord_y, std::string path_history, char ch);
    std::vector<Mouse> spawn_mice();
    std::string& path();
private:
    int x{};
    int y{};
    std::string _path{};
};

Mouse::Mouse(int n)
{
    x = y = n;
}

Mouse::Mouse(int coord_x, int coord_y, std::string path_history, char ch)
{
    _path = path_history + ch;
    x = coord_x;
    y = coord_y;
}

std::vector<Mouse> Mouse::spawn_mice()
{
    std::vector<Mouse> mice{};
    if (x > 0) {
        Mouse mouse_x(x - 1, y, _path, 'r');
        mice.push_back(mouse_x);
    }
    if (y > 0) {
        Mouse mouse_y(x, y - 1, _path, 'd');
        mice.push_back(mouse_y);
    }
    return mice;
}

std::string& Mouse::path()
{
    return _path;
}

class Square_Grid {
public:
    explicit Square_Grid(int n);
    void find_paths();
    void print_paths();
private:
    std::vector<Mouse> mice{};
    int a;
};

Square_Grid::Square_Grid(int n)
{
    a = n;
    Mouse start(a);
    mice.push_back(start);
}

void Square_Grid::find_paths()
{
    std::vector<Mouse> new_mice;
    for (auto i : mice) {
        std::vector<Mouse> temp_mice = i.spawn_mice();
        for (const auto& j : temp_mice) {
            new_mice.push_back(j);
        }
    }
    mice = new_mice;
}

void Square_Grid::print_paths()
{
    std::cout << "Number of paths: " << mice.size() << "\n";
    for (auto& m : mice) {
        std::cout << m.path() << "\n";
    }
};

int main()
{
    int SIZE = 4;
    Square_Grid grid(SIZE);
    for (int i = 0; i < 2 * SIZE; i++) {
        grid.find_paths();
    }
    grid.print_paths();
}

// all you need to do is calculate the permutations of the multiset lol
// the above code is unnecessary
// (r+d)!/(r!*d!)
// r : right, d : down
// no matter which route we take, in the square grid a x a, we will always take
// a steps to the right and a steps down
