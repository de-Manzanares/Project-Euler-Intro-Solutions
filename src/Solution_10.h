#ifndef PROJECTEULERSOLUTIONS_SOLUTION_10_H
#define PROJECTEULERSOLUTIONS_SOLUTION_10_H

class Solution_10 {
public:
    static void print_solution(int ceiling)
    {
        std::vector<size_t> primeList = {2};
        size_t number;
        size_t sum = 0;
        bool hasPrimeFactor;
        bool provenComposite;
        bool generatePrimes = true;

        for (number = 3; generatePrimes; number++) {
            provenComposite = false;
            for (int i = 0; i < primeList.size() && !provenComposite; i++) {
                hasPrimeFactor = (number % primeList[i] == 0);
                if (hasPrimeFactor) {
                    provenComposite = true;
                }
            }
            if (!provenComposite) {
                primeList.push_back(number);
            }
            generatePrimes = number < SIZE_MAX && primeList.back() < ceiling;
        }
        if (primeList.back() > ceiling) {
            primeList.pop_back();
        }
        for (int i = 0; i < primeList.size(); i++) {
            sum += primeList[i];
        }
        std::cout << sum << std::endl;
    }
};

#endif //PROJECTEULERSOLUTIONS_SOLUTION_10_H
