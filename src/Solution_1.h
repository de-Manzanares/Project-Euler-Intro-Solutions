#ifndef PROJECTEULERSOLUTIONS_SOLUTION_1_H
#define PROJECTEULERSOLUTIONS_SOLUTION_1_H

#include <iostream>
#include <vector>
#include <algorithm>

class Solution_1 {
public:
    static void print_solution(std::vector<int> number, int limit)
    {
        std::vector<int> multiples;
        int sum = 0;
        for (int i = 0; i < number.size(); i++) {
            for (int j = 1; number[i] * j < limit; j++) {
                multiples.push_back(number[i] * j);
            }
        }
        for (int i = 0; i < multiples.size(); i++) {
            std::sort(multiples.begin(), multiples.end());
            multiples.erase(
                    std::unique(multiples.begin(), multiples.end()),
                    multiples.end());
        }
        for (int i = 0; i < multiples.size(); i++) {
            sum += multiples[i];
        }
        std::cout << sum << std::endl;
    }
};

#endif //PROJECTEULERSOLUTIONS_SOLUTION_1_H
