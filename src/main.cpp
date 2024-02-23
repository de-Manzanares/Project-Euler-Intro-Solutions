/// @file main.cpp
/// @brief Entry to the subprograms

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

#include "Selector.hpp"

// TODO(dm) solution prompts and explanations
// TODO(dm) figure out install config -- prompt files and problem data files

int main()
{
    while (Selector::keep_goin) {
        Selector::select();
    }

    return 0;
}
