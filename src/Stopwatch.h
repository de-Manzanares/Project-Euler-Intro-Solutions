/*
 * Simple stopwatch to measure code block execution times
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
 */

#ifndef PROJECTEULERSOLUTIONS_STOPWATCH_H
#define PROJECTEULERSOLUTIONS_STOPWATCH_H

#include <chrono>
#include <iostream>
#include <iomanip>
#include "util.h"

class Stopwatch {
public:
    void start() { begin = std::chrono::steady_clock::now(); }

    void stop() { end = std::chrono::steady_clock::now(); }

    void print_readout()
    {
        std::cout
                << insert_commas(
                        static_cast<size_t>(
                                std::chrono::duration_cast
                                        <std::chrono::nanoseconds>
                                        (end - begin).count()))
                << " ns" << "\n"
                << insert_commas(
                        static_cast<size_t>(
                                std::chrono::duration_cast
                                        <std::chrono::microseconds>
                                        (end - begin).count()))
                << " us" << "\n"
                << insert_commas(
                        static_cast<size_t>(
                                std::chrono::duration_cast
                                        <std::chrono::milliseconds>
                                        (end - begin).count()))
                << " ms" << "\n"
                << insert_commas(
                        static_cast<size_t>(
                                std::chrono::duration_cast
                                        <std::chrono::seconds>
                                        (end - begin).count()))
                << " s" << "\n"
                << insert_commas(
                        static_cast<size_t>(
                                std::chrono::duration_cast
                                        <std::chrono::minutes>
                                        (end - begin).count()))
                << " min" << "\n";
    }

    void print_readout_old()
    {
        std::cout
                << std::chrono::duration_cast
                        <std::chrono::nanoseconds>
                        (end - begin).count()
                << " ns" << "\n"
                << std::chrono::duration_cast
                        <std::chrono::microseconds>
                        (end - begin).count()
                << " us" << "\n"
                << std::chrono::duration_cast
                        <std::chrono::milliseconds>
                        (end - begin).count()
                << " ms" << "\n"
                << std::chrono::duration_cast
                        <std::chrono::seconds>
                        (end - begin).count()
                << " s" << "\n"
                << std::chrono::duration_cast
                        <std::chrono::minutes>
                        (end - begin).count()
                << " min" << "\n";
    }

private:
    std::chrono::steady_clock::time_point begin, end;
};

#endif //PROJECTEULERSOLUTIONS_STOPWATCH_H