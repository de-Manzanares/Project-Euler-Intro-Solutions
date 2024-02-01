#ifndef PROJECTEULERSOLUTIONS_SOLUTION_2_H
#define PROJECTEULERSOLUTIONS_SOLUTION_2_H

#include <vector>

class Solution_2 {
public:
    static void print_solution()
    {
        size_t sum = 0;
        std::vector<int> fibonacciSequence = {1, 2};
        std::vector<int> evenFibonacciNumbers;

        // Get Fibonacci sequence up to 4x10^6
        for (int i = 0; fibonacciSequence.back() < 4'000'000; i++) {
            fibonacciSequence.push_back(
                    fibonacciSequence[i] + fibonacciSequence[i + 1]);
        }
        if (fibonacciSequence.back() > 4'000'000) {
            fibonacciSequence.pop_back();
        }
        // Get even Fibonacci numbers
        for (int i : fibonacciSequence) {
            if (i % 2 == 0) {
                evenFibonacciNumbers.push_back(i);
            }
        }
        // Sum even Fibonacci numbers
        for (int evenFibonacciNumber : evenFibonacciNumbers) {
            sum += evenFibonacciNumber;
        }
        std::cout << sum << std::endl;
    }
};

#endif //PROJECTEULERSOLUTIONS_SOLUTION_2_H
