//  Solution 17
//  Copyright (c) 2024. de-Manzanares
//  Contact: git.in.touch@dmanz.org
//
//      This program is free software: you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation, either version 3 of the License, or
//      (at your option) any later version.
//
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY, without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//
//      You should have received a copy of the GNU General Public License
//      along with this program.  If not, see <https://www.gnu.org/licenses/>.
//
//  https://projecteuler.net/problem=17

#include <iostream>
#include <vector>

int main()
{
// all the words to be used defined as their character count
    int one = 3,
            two = 3,
            three = 5,
            four = 4,
            five = 4,
            six = 3,
            seven = 5,
            eight = 5,
            nine = 4,
            ten = 3,
            eleven = 6,
            twelve = 6,
            thirteen = 8,
            fourteen = 8,
            fifteen = 7,
            sixteen = 7,
            seventeen = 9,
            eighteen = 8,
            nineteen = 8,
            twenty = 6,
            thirty = 6,
            forty = 5,
            fifty = 5,
            sixty = 5,
            seventy = 7,
            eighty = 6,
            ninety = 6,
            hundred = 7,
            thousand = 8,
            _and = 3;

// multiply by their frequency and sum the results

    int sum =
// ones
// strings "one" through "nine" appear
// once for each number within their respective hundred bracket
// (e.g. 200, 201, 202, ... 298, 299)
// and nine times each within other hundred
// for example, "one" appears 9 times before 100 and 9 times in 200, 300 and
// so on
// "one" makes an additional appearance in "one thousand"
            (one * (100 + 9 * 9 + 1))
                    + (two * (100 + 9 * 9))
                    + (three * (100 + 9 * 9))
                    + (four * (100 + 9 * 9))
                    + (five * (100 + 9 * 9))
                    + (six * (100 + 9 * 9))
                    + (seven * (100 + 9 * 9))
                    + (eight * (100 + 9 * 9))
                    + (nine * (100 + 9 * 9))
// teens
// strings "ten" through "nineteen" appear once per hundred
// 010, 011, ... , 018, 019
// 110, 111, ... , 118, 119
// 210, 211, ... , 218, 219
// ...
// 910, 911, ... , 918, 919
                    + (ten * 10)
                    + (eleven * 10)
                    + (twelve * 10)
                    + (thirteen * 10)
                    + (fourteen * 10)
                    + (fifteen * 10)
                    + (sixteen * 10)
                    + (seventeen * 10)
                    + (eighteen * 10)
                    + (nineteen * 10)
// tens
// strings "twenty" through "ninety" appear once per hundred
// 020, 120, 220, ... , 920
// 030, 130, 230, ... , 930
// ...
// 090, 190, 290, ... , 990
                    + (twenty * 10)
                    + (thirty * 10)
                    + (forty * 10)
                    + (fifty * 10)
                    + (sixty * 10)
                    + (seventy * 10)
                    + (eighty * 10)
                    + (ninety * 10)

// the string "hundred" appears once for every number greater than 99 and less
// than 1000
                    + (hundred * (100 * 9 - 1))

// the string "thousand" appears once
                    + (thousand * 1)

// the string "and" appears once for every number greater than 100, excluding
// every round hundred (e.g. 200, 300, etc.) and 1000
                    + (_and * (99 * 9));

    std::cout << sum << "\n";

    std::vector<std::string> ones = {"", "one", "two", "three", "four", "five",
                                     "six", "seven", "eight",
                                     "nine"};
    std::vector<std::string> teens = {"ten", "eleven", "twelve", "thirteen",
                                      "fourteen", "fifteen", "sixteen",
                                      "seventeen", "eighteen", "nineteen"};
    std::vector<std::string> tens = {"twenty", "thirty", "forty", "fifty",
                                     "sixty", "seventy", "eighty", "ninety"};
    std::string big_string;
    std::string prefix;
    std::string __and;
    for (int i = 0; i < 10; ++i) {
        prefix = ones[i] + (i > 0 ? "-hundred " : "");
        for (const auto& word : ones) {
            __and = (!prefix.empty() && !word.empty() != 0 ? "and " : "");
            big_string += prefix + __and + word + " ";
        }
        for (const auto& word : teens) {
            big_string += prefix + __and + word + " ";
        }
        for (const auto& word_tens : tens) {
            for (const auto& word_ones : ones) {
                std::string hyphen = (word_ones.empty() ? "" : "-");
                big_string +=
                        prefix + __and + word_tens + hyphen + word_ones + " ";
            }
        }
    }
    big_string += "one thousand";
    std::cout << big_string << "\n";
    sum = 0;
    for (const auto& ch : big_string) {
        if (ch != '-' && ch != ' ') {
            ++sum;
        }
    }
    std::cout << sum << "\n";
}

// I have no idea why my initial guess is WAY TOO LOW ...
// LOL
