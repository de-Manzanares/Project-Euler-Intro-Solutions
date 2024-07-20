/*
 *  https://projecteuler.net/problem=2
 *  Each new term in the Fibonacci sequence is generated by adding the previous
 * two terms. By starting with 1 and 2, the first 10 terms will be: 1, 2, 3, 5,
 * 8, 13, 21, 34, 55, 89, ... By considering the terms in the Fibonacci sequence
 * whose values do not exceed four million, find the sum of the even-valued
 * terms.
 */

#include <iostream>

int main() {
  int total = 0;

  for (int a = 1, b = 2, next; a < 4'000'000; next = a + b, a = b, b = next) {
    if (a % 2 == 0) {
      total += a;
    }
  }

  std::cout << total << std::endl;
  return 0;
}
