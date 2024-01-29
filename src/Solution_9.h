#ifndef PROJECTEULERSOLUTIONS_SOLUTION_9_H
#define PROJECTEULERSOLUTIONS_SOLUTION_9_H

#include <iostream>

class Solution_9 {
public:
    static void print_solution()
    {
        // check all the ways 3 numbers can sum to 1000
        // check if a^2+b^2=c^2
        int SUM = 1000;
        int b;
        int c;
        int j = 0;

        for (int a = 1; a<=SUM-2; a++) {
            b = 1;
            c = SUM-(a+b);
            for (int i = 0; i<(SUM-(2+j)); i++) {
                // std::cout << "a = " << a << "\tb = " << b << "\tc = " << c <<
                //           "\tsum = " << a+b+c << std::endl;
                if (a*a+b*b==c*c) {
                    std::cout << "Pythagorean triplet found: "
                              << "a = " << a << "\tb = " << b << "\tc = " << c
                              << std::endl;
                    std::cout << "Product `abc` = " << a*b*c << std::endl;
                }
                b += 1;
                c -= 1;
            }
            j++;
        }
    }
};

#endif //PROJECTEULERSOLUTIONS_SOLUTION_9_H
