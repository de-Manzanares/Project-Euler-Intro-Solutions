//  Solution 20
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
//  https://projecteuler.net/problem=20

#include <iostream>

const size_t DIGITS = 202;     // log_10(100^100)=200

class reallyLongInt {
public:
    friend std::ostream&
    operator<<(std::ostream& osObject, const reallyLongInt& cObject);
    reallyLongInt& operator=(const std::string& number_string);
    int operator[](int index);
    int operator[](int index) const;
    reallyLongInt& operator+=(const reallyLongInt& rhs);
    reallyLongInt& operator*=(int n);
    int sum_of_digits();

    int *begin() { return &big_number[0]; }

    int *end() { return &big_number[DIGITS]; }

private:
    int big_number[DIGITS]{};
};

std::ostream& operator<<(std::ostream& osObject, const reallyLongInt& cObject)
{
    bool leading_zeroes_skipped = false;
    for (int i = 0; i < DIGITS; ++i) {
        if (leading_zeroes_skipped) {
            std::cout << cObject[i];
        }
        else if (cObject[i] != 0) {
            std::cout << cObject[i];
            leading_zeroes_skipped = true;
        }
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
            carry = temp_string[0] - '0';
        }
    }
    for (int i = 0; i < DIGITS; ++i) {
        this->big_number[i] = temp_array[i];
    }
    return *this;
}

// doesn't do zero or negatives
reallyLongInt& reallyLongInt::operator*=(int n)
{
    reallyLongInt temp(*this);

    for (int i = 0; i < n - 1; i++) {
        *this += temp;
    }
    return *this;
}

int reallyLongInt::sum_of_digits()
{
    int sum = 0;
    for (const auto& digit : *this) {
        sum += digit;
    }
    return sum;
}

int main()
{
    reallyLongInt a;
    a = "100";
    for (int i = 99; i > 0; i--) {
        a *= i;
    }
    std::cout << a << "\n"
              << "Sum of digits: " << a.sum_of_digits();
}
