#ifndef PROJECTEULERSOLUTIONS_SOLUTION_7_H
#define PROJECTEULERSOLUTIONS_SOLUTION_7_H

#include <cstdint>
#include <iostream>
#include <vector>

class Solution_7 {
public:
    static void print_solution(int nthPrime)
    {
        std::vector<size_t> primeList = {2};
        size_t number;
        bool hasPrimeFactor;
        bool provenComposite;
        bool generatePrimes = true;

        for (number = 3; generatePrimes; number++) {
            provenComposite = false;
            for (int i = 0; i<primeList.size() && !provenComposite; i++) {
                hasPrimeFactor = (number%primeList[i]==0);
                if (hasPrimeFactor) {
                    provenComposite = true;
                }
            }
            if (!provenComposite) {
                primeList.push_back(number);
            }
            generatePrimes = number<SIZE_MAX && primeList.size()<nthPrime;
        }
        std::cout << primeList[nthPrime-1] << std::endl;
    }
};

#endif //PROJECTEULERSOLUTIONS_SOLUTION_7_H
