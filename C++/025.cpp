/*
 * https://projecteuler.net/problem=25
 */

#include <gmp.h>
#include <gmpxx.h>
#include <iostream>

// gmp is crazy awesome
int main() {
  mpz_t target;
  mpz_init_set_ui(target, 10);
  mpz_pow_ui(target, target, 999);

  mpz_t n;
  mpz_init_set_ui(n, 0);

  for (unsigned long i = 0; i < std::numeric_limits<int>::max(); ++i) {
    mpz_fib_ui(n, i);
    if (mpz_cmp(n, target) >= 0) {
      gmp_printf("%Zd\n", n);
      std::cout << i << '\n';
      break;
    }
  }

  mpz_clear(n);
}
