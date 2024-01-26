#ifndef PROJECTEULERSOLUTIONS_STOPWATCH_H
#define PROJECTEULERSOLUTIONS_STOPWATCH_H

#include <chrono>
#include <iostream>
#include <iomanip>

class Stopwatch {
public:
    void start()
    {
        begin = std::chrono::steady_clock::now();
    }
    void stop()
    {
        end = std::chrono::steady_clock::now();
        std::cout << std::fixed << std::showpoint << std::setprecision(9)
                  << std::chrono::duration_cast<std::chrono::
                  nanoseconds>(end-begin).count()
                  << " ns" << "\n"
                  << std::chrono::duration_cast<std::chrono::
                  microseconds>(end-begin).count()
                  << " us" << "\n"
                  << std::chrono::duration_cast<std::chrono::
                  milliseconds>(end-begin).count()
                  << " ms" << "\n"
                  << std::chrono::duration_cast<std::chrono::
                  seconds>(end-begin).count()
                  << " s" << "\n"
                  << std::chrono::duration_cast<std::chrono::
                  minutes>(end-begin).count()
                  << " min" << "\n";
    }
private:
    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;
};

#endif //PROJECTEULERSOLUTIONS_STOPWATCH_H
