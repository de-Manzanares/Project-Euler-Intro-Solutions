/**
 * <p>$2520$ is the smallest number that can be divided by each of the numbers
 * from $1$ to $10$ without any remainder.</p> <p>What is the smallest positive
 * number that is <strong class="tooltip">evenly divisible<span
 * class="tooltiptext">divisible with no remainder</span></strong> by all of the
 * numbers from $1$ to $20$?</p>
 */

#include "../../../../usr/include/limits.h"

#include <iostream>

using ull = unsigned long long;

template <class T> bool divisibleByAll(T n) {
  for (int i = 20; i > 0; i--) {
    if (n % i != 0) {
      return false;
    }
  }
  return true;
}

int main() {
  ull i = 20 * 19;
  while (!divisibleByAll(i)) {
    i++;
  }
  std::cout << i;
  return 0;
}
