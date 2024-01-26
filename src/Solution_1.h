#ifndef PROJECTEULERSOLUTIONS_SOLUTION_1_H
#define PROJECTEULERSOLUTIONS_SOLUTION_1_H

#include <iostream>
#include <vector>

class Solution_1 {
public:
    static void print_solution(std::vector<double> number, double limit)
    {
        double sum = 0;
        for (int i = 0; i<number.size(); i++) {
            for (int j = 1; number[i]*j<limit; j++) {
                sum += number[i]*j;
            }
        }
        std::cout << sum << std::endl;
    }
};
#endif //PROJECTEULERSOLUTIONS_SOLUTION_1_H
