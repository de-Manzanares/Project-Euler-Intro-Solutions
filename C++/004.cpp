/**
 * <p>A palindromic number reads the same both ways. The largest palindrome made
 * from the product of two $2$-digit numbers is $9009 = 91 \times 99$.</p>
 * <p>Find the largest palindrome made from the product of two $3$-digit
 * numbers.</p>
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

template <class T> bool is_palindrome(const T n) {
  static_assert(std::is_integral_v<T>);
  auto m = std::to_string(n);
  std::reverse(m.begin(), m.end());
  return std::to_string(n) == m;
}

std::vector<ulong> v{0, 0, 0};

int main() {
  for (auto i = static_cast<ulong>(std::pow(100, 2));
       i < static_cast<ulong>(std::pow(999, 2)); i++) {
    if (is_palindrome(i)) {
      for (ulong j = 100; j < 1000; j++) {
        if (i % j == 0 && i / j < 1000) {
          v = std::vector{i, j, i / j};
          break;
        }
      }
    }
  }
  for (const auto &a : v) {
    std::cout << a << " ";
  }
  return 0;
}
