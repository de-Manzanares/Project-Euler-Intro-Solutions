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
// https://projecteuler.net/problem=13
//

#include <iostream>
#include "Stopwatch.hpp"

// max size in digits of custom integer type
const size_t DIGITS = 53;

class reallyLongInt {
public:
    friend std::ostream&
    operator<<(std::ostream& osObject, const reallyLongInt& cObject);
    reallyLongInt& operator=(const std::string& number_string);
    int operator[](int index);
    int operator[](int index) const;
    reallyLongInt& operator+=(const reallyLongInt& rhs);

private:
    int big_number[DIGITS]{};
};

std::ostream& operator<<(std::ostream& osObject, const reallyLongInt& cObject)
{
    for (int i = 0; i < DIGITS; ++i) {
        osObject << cObject[i];
    }
    return osObject;
}

int reallyLongInt::operator[](int index)
{
    return big_number[index];
}

int reallyLongInt::operator[](int index) const
{
    return big_number[index];
}

reallyLongInt& reallyLongInt::operator=(const std::string& number_string)
{
    size_t index = DIGITS - number_string.size();
    for (size_t i = 0; i < number_string.size(); ++i) {
        big_number[index] = number_string[i] - '0';
        ++index;
    }
    return *this;
}

reallyLongInt& reallyLongInt::operator+=(const reallyLongInt& rhs)
{
    int carry = 0;
    int temp_array[DIGITS];
    for (int i = DIGITS - 1; i > -1; --i) {
        if (this->big_number[i] + rhs[i] + carry <= 9) {
            temp_array[i] = this->big_number[i] + rhs[i] + carry;
            carry = 0;
        }
        else {
            std::string temp_string =
                    std::to_string(this->big_number[i] + rhs[i] + carry);
            temp_array[i] = temp_string[1] - '0';
            // temp_array[--i] = temp_string[0] - '0';
            carry = temp_string[0] - '0';
        }
    }
    for (int i = 0; i < DIGITS; ++i) {
        this->big_number[i] = temp_array[i];
    }
    return *this;
}

int main()
{
    Stopwatch stopwatch;
    const int ARRAY_SIZE = 102;
    std::string line;
    reallyLongInt number[ARRAY_SIZE];
    int i = 0;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            break;
        }
        number[i + 1] = line;
        ++i;
    }
    stopwatch.start();
    for (int i = 1; i < ARRAY_SIZE; i++) {
        number[0] += number[i];
    }
    std::cout << number[0] << "\n";
    stopwatch.stop();
    stopwatch.print_readout();
    return 0;
}

// turns out, to find the first 10 digits of the sum, you only need to add the
// first 13 digits of every number. Assuming the thirteenth digit of each number
// is 9, and there are 100 numbers, the maximum impact the thirteenth digit
// could have is 9E-13 x 100 = 9E-11, affecting only the digit in the 11th
// place.
