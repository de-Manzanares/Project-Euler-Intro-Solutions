/*
 * Solution 8
 * Copyright (c) 2024. de-Manzanares
 * Contact: git.in.touch@dmanz.org
 *
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * https://projecteuler.net/problem=8
 */

// TODO division by 0
// ==44279== Process terminating with default action of signal 8 (SIGFPE)
//==44279==  Integer divide by zero at address 0x1002EE4EF5
//==44279==    at 0x10D915: Solution_008::calculate_fast_product() (Solution_008.h:59)
//==44279==    by 0x10D83C: Solution_008::print_solution() (Solution_008.h:45)
//==44279==    by 0x10BDDC: Solution::select(int) (Solution.h:77)
//==44279==    by 0x10BFC1: main (main.cpp:13)
//==44279==
//==44279== HEAP SUMMARY:
//==44279==     in use at exit: 1,074,809 bytes in 5 blocks
//==44279==   total heap usage: 5 allocs, 0 frees, 1,074,809 bytes allocated
//==44279==
//==44279== LEAK SUMMARY:
//==44279==    definitely lost: 0 bytes in 0 blocks
//==44279==    indirectly lost: 0 bytes in 0 blocks
//==44279==      possibly lost: 0 bytes in 0 blocks
//==44279==    still reachable: 1,074,809 bytes in 5 blocks
//==44279==         suppressed: 0 bytes in 0 blocks
//==44279== Rerun with --leak-check=full to see details of leaked memory
//==44279==
//==44279== For lists of detected and suppressed errors, rerun with: -s
//==44279== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
//Floating point exception (core dumped)

#ifndef PROJECTEULERSOLUTIONS_SOLUTION_8_H
#define PROJECTEULERSOLUTIONS_SOLUTION_8_H

#include <string>
#include <iostream>

class Solution_008 {
public:
    // BEGIN SOLUTION
    //--------------------------------------------------------------------------
    void print_solution()
    {
        Stopwatch stopwatch;
        stopwatch.start();
        for (index = 0; index < series.size() - (ADJACENT_DIGITS); index++) {

            skip_zeroes();
            if (calculate_slow_product() == 0) {
                skip_zeroes();
                calculate_slow_product();
            }
            check_max();
            if (series[index] - '0' != 0) {
                while (calculate_fast_product() != 0) {
                    check_max();
                    index++;
                }
            }
        }
        std::cout << maxProduct << std::endl;
        stopwatch.stop();
    }
    // END SOLUTION
    //--------------------------------------------------------------------------

    size_t calculate_fast_product()
    {
        temporaryProduct = (temporaryProduct / (series[index] - '0')) *
                ((series[index + ADJACENT_DIGITS]) - '0');

        return temporaryProduct;
    }

    size_t calculate_slow_product()
    {
        size_t slowProduct = 1;
        for (int j = 0; j < ADJACENT_DIGITS; j++) {
            slowProduct *= series[index + j] - '0';
        }
        temporaryProduct = slowProduct;
        return temporaryProduct;
    }

    void check_max()
    {
        if (temporaryProduct > maxProduct) {
            maxProduct = temporaryProduct;
        }
    }

    int distance_to_zero()
    {
        int indexShift{};
        for (int j = 0; j < ADJACENT_DIGITS; j++) {
            if ((series[index + j] - '0') == 0) {
                indexShift = j;
            }
            // if there is a zero underfoot, move 1
            if (indexShift == 0
                    && series[index] == 0) {
                indexShift = 1;
            }
        }
        return indexShift;
    }

    void skip_zeroes()
    {
        while (distance_to_zero() != 0) {
            index = index + distance_to_zero();
        }
    }

    int ADJACENT_DIGITS;
    int index;
    size_t temporaryProduct;
    size_t maxProduct;
    std::string series =

            "73167176531330624919225119674426574742355349194934"
            "96983520312774506326239578318016984801869478851843"
            "85861560789112949495459501737958331952853208805511"
            "12540698747158523863050715693290963295227443043557"
            "66896648950445244523161731856403098711121722383113"
            "62229893423380308135336276614282806444486645238749"
            "30358907296290491560440772390713810515859307960866"
            "70172427121883998797908792274921901699720888093776"
            "65727333001053367881220235421809751254540594752243"
            "52584907711670556013604839586446706324415722155397"
            "53697817977846174064955149290862569321978468622482"
            "83972241375657056057490261407972968652414535100474"
            "82166370484403199890008895243450658541227588666881"
            "16427171479924442928230863465674813919123162824586"
            "17866458359124566529476545682848912883142607690042"
            "24219022671055626321111109370544217506941658960408"
            "07198403850962455444362981230987879927244284909188"
            "84580156166097919133875499200524063689912560717606"
            "05886116467109405077541002256983155200055935729725"
            "71636269561882670428252483600823257530420752963450";
};

#endif  // PROJECTEULERSOLUTIONS_SOLUTION_8_H