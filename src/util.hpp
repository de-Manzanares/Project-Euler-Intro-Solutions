/// @file util.cpp
/// @brief general purpose functions

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

#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_

#include <string>

std::string insert_commas(size_t num) {
    std::string string = std::to_string(num);
    auto length = string.length();
    if (length > 3) {
        auto partLength = length % 3;
        partLength = (partLength == 0) ? 3 : partLength;
        std::string formatted = string.substr(0, partLength);
        for (auto i = partLength; i < length; i += 3) {
            formatted += ',' + string.substr(i, 3);
        }
        string = formatted;
    }
    return string;
}

#endif  // SRC_UTIL_H_
