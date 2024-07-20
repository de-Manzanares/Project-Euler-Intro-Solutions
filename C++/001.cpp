/*
 *  https://projecteuler.net/problem=1
 *  If we list all the natural numbers below 10 that are multiples of 3 or 5, we
 * get 3, 5, 6 and 9. The sum of these multiples is 23. Find the sum of all the
 * multiples of 3 or 5 below 1000.
 */

#include <iostream>

int p001_0() {
  int sum = 0;
  for (int i = 1; i < 1000; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }
  return sum;
}

template <typename T, typename... Args> T p001_1(T limit, Args... args) {
  T sum{};
  for (T n = 0; n < limit; ++n) {
    if (((n % args == 0) || ...)) {
      sum += n;
    }
  }
  return sum;
}

int main() {
  std::cout << p001_0() << '\n';
  std::cout << p001_1<uint64_t>(1000, 3, 5);
  return 0;
}
