#ifndef PROJECTEULERSOLUTIONS_SOLUTION_4_H
#define PROJECTEULERSOLUTIONS_SOLUTION_4_H

#include <iostream>
#include <string>

bool checkPalindrome(int x);

class Solution_4 {
public:
    static void print_solution()
    {
        std::vector<int> palindromes;
        int temporaryPalindrome;
        int maxPalindrome;

        for (int i = 999; i>99; i--) {
            if (i%11==0) {
                for (int j = 999; j>99; j--) {
                    if (checkPalindrome(i*j)
                            && (temporaryPalindrome = i*j)>maxPalindrome) {
                        maxPalindrome = temporaryPalindrome;
                    }
                }
            }
        }
        std::cout << maxPalindrome << std::endl;
    }
};

bool checkPalindrome(int x)
{
    std::string str_x = std::to_string(x);
    int front = 0;
    int back = static_cast<int>(str_x.size()-1);
    bool provenFalse = false;
    int i = 0;

    while (!provenFalse && i<(str_x.size()/2+str_x.size()%2)) {
        if (str_x[front+i]!=str_x[back-i]) {
            provenFalse = true;
        }
        i++;
    }
    return !provenFalse;
}

#endif //PROJECTEULERSOLUTIONS_SOLUTION_4_H
