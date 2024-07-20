/**
 *  https://projecteuler.net/problem=3
 *  The prime factors of 13195 are 5, 7, 13 and 29.
 *  What is the largest prime factor of the number 600851475143?
 */

#include <iostream>

int main() {
  // to find the largest prime factor, we have to find all the prime factors
  // to find the prime factors of a number, divide out all the 2's
  ulong i = 3;
  ulong n = 600851475143;
  while (n % 2 == 0) {
    n /= 2;
  }
  if (n == 1) {
    std::cout << "2";
    return 0;
  }
  while (n != 1) {
    while (n % i == 0) {
      n /= i;
    }
    i++;
  }
  i--;
  std::cout << i;
}
