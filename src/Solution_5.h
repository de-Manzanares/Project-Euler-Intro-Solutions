#ifndef PROJECTEULERSOLUTIONS_SOLUTION_5_H
#define PROJECTEULERSOLUTIONS_SOLUTION_5_H

#include <cstddef>
#include <cmath>

class Solution_5 {
public:
    static void print_solution()
    {
        bool found = false;
        bool failed;
        int j;

        for (size_t i = (20*19);
             i<static_cast<size_t>(pow(2, 64)) && !found;
             i++) {
            failed = false;
            j = 20;
            while (!found && !failed && j>0) {
                if (i%j!=0) {
                    failed = true;
                }
                j--;
                if (j==1 && !failed) {
                    found = true;
                }
            }
            if (found) {
                std::cout << i << std::endl;
            }
        }
    }
};

#endif //PROJECTEULERSOLUTIONS_SOLUTION_5_H
