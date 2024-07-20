/**
 * <p>By listing the first six prime numbers: $2, 3, 5, 7, 11$, and $13$, we can
 * see that the $6$th prime is $13$.</p> <p>What is the $10\,001$st prime
 * number?</p>
 */

#include <iostream>
#include <vector>

int main() {
  // all primes, except 2, are odd
  // make a list of primes
  // check against the list -> add or move on
  // count to 10'001

  constexpr auto N = 10'001; // NOLINT
  std::vector primes{2};
  primes.reserve(N);

  for (auto i = 3; primes.size() < N; i += 2) {
    bool composite = false;
    for (const auto &prime : primes) {
      if (i % prime == 0) {
        composite = true;
        break;
      }
    }
    if (!composite) {
      primes.push_back(i);
    }
  }
  std::cout << primes.back() << "\n";
}