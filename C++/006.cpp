/**
 * <p>The sum of the squares of the first ten natural numbers is,</p>
 * $$1^2 + 2^2 + ... + 10^2 = 385.$$
 * <p>The square of the sum of the first ten natural numbers is,</p>
 * $$(1 + 2 + ... + 10)^2 = 55^2 = 3025.$$
 * <p>Hence the difference between the sum of the squares of the first ten
 * natural numbers and the square of the sum is $3025 - 385 = 2640$.</p> <p>Find
 * the difference between the sum of the squares of the first one hundred
 * natural numbers and the square of the sum.</p>
 */

#include <iostream>

using ull = unsigned long long;

template <class Ull> Ull difference(Ull n) {
  static_assert(std::is_integral_v<Ull>);
  auto sum_of_squares = [n] {
    Ull sosq = 0;
    for (Ull i = 0; i <= n; ++i) {
      sosq += i * i;
    }
    return sosq;
  }();
  Ull square_of_sums = [n] {
    Ull sqos = 0;
    for (Ull i = 0; i <= n; ++i) {
      sqos += i;
    }
    sqos *= sqos;
    return sqos;
  }();
  return square_of_sums - sum_of_squares;
}

int main() { std::cout << difference(100); }
