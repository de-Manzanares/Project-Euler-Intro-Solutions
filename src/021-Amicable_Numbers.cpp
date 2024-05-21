//  Solution 21 - Amicable Numbers
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
//  https://projecteuler.net/problem=21

// d(n) sum of proper divisors of a number
// define a proper divisor
// make a list of proper divisors of a given number
// sum them lol
// start with


#include <type_traits>
#include <vector>
#include <iostream>

template<typename T>
bool is_proper_divisor(T divisor, T n)
{
    static_assert(std::is_integral<T>::value);

    return n % divisor == 0;
}

template<typename T>
std::vector<T> list_proper_divisors(T n)
{
    static_assert(std::is_integral<T>::value);

    std::vector<T> proper_divisors{};

    for (T i = 1; i < n; i++) {
        if (is_proper_divisor(i, n)) {
            proper_divisors.push_back(i);
        }
    }
    return proper_divisors;
}

template<typename T>
T sum_vector(std::vector<T> v)
{
    static_assert(std::is_arithmetic<T>::value);

    T sum{};

    for (const auto& n : v) {
        sum += n;
    }
    return sum;
}

int main()
{
    std::vector<std::vector<int>> amicable_numbers;

    for (int a = 2; a < 10001; a++) {
        int b;
        int x;
        b = sum_vector(list_proper_divisors(a));
        x = sum_vector(list_proper_divisors(b));
        if (x == a && a != b) {
            std::cout << a << " " << b << "\n";
            amicable_numbers.push_back({a, b});
        }
    }

    int sum{};
    for (const auto& v : amicable_numbers) {
        sum += sum_vector(v);
    }

    std::cout << sum / 2; // divide by 2 because all pairs are duplicated

    return 0;
}
