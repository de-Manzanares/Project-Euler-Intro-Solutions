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
// https://projecteuler.net/problem=14
//

#define PRINT_SEQUENCE_YES

#include <iostream>

int main()
{
    unsigned int START = 500;     // search starts at
    unsigned int END = 2500;     // searches search ends with (inclusive)
    unsigned long long n{};
    unsigned int N{};
    unsigned long long temp_sequence_length{};
    unsigned long long max_sequence_length{};

    // if even n = n/2
    // if odd n = 3n+1
#ifdef PRINT_SEQUENCE_YES
    std::cout << "{\n";
#endif
    for (auto i = START; i <= END; ++i) {
#ifdef PRINT_SEQUENCE_YES
        std::cout << '{';
#endif
        n = i;
        do {
#ifdef PRINT_SEQUENCE_YES
            std::cout << n << ',';
#endif
            if (n % 2 == 0) {
                n /= 2;
            }
            else {
                n = 3 * n + 1;
            }
            ++temp_sequence_length;
        }
        while (n != 1);
#ifdef PRINT_SEQUENCE_YES
        std::cout << "1},\n";
#endif
        if (temp_sequence_length > max_sequence_length) {
            max_sequence_length = temp_sequence_length;
            N = i;
        }
        temp_sequence_length = 0;
    }
#ifdef PRINT_SEQUENCE_YES
    std::cout << "}\n";
#endif
    std::cout << "Number:          " << N << "\n"
              << "Sequence length: " << max_sequence_length << "\n";
}

// interesting to note, the sequence will end in 1 in m steps if it ever
// reaches a value 2^m .
