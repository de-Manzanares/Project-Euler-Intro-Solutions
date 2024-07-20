/* <p>A Pythagorean triplet is a set of three natural numbers, $a \lt b \lt c$,
 * for which,
 * $$a^2 + b^2 = c^2.$$</p>
 * <p>For example, $3^2 + 4^2 = 9 + 16 = 25 = 5^2$.</p>
 * <p>There exists exactly one Pythagorean triplet for which $a + b + c =
 * 1000$.<br>Find the product $abc$.</p>
 */

#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

template <typename T> std::vector<T> p009();

template <typename Arg, typename... Args>
void print(std::ostream &out, Arg &&arg, Args &&...args) {
  out << std::forward<Arg>(arg);
  ((out << ' ' << std::forward<Args>(args)), ...);
}

int main() {
  for (const auto &n : p009<int>()) {
    std::cout << n << ' ';
  }
  std::cout << '\n';
  return EXIT_SUCCESS;
}

template <typename T> std::vector<T> p009() {
  // check if a^2+b^2 == c^2
  // maintaining c > b, give from c to b until b - a > 1
  // increment a and check if a^2+b^2 == c^2 until b - a == 1
  // reset a back to 1 and increase c by a - 1 (maintain a+b+c == 1000)
  // maintaining c > b, give from c to b until b - a > 2 ...

  T c = 997;
  T b_target = 2;
  T b = 2;
  T a = 1;

  while (c > b && b > a) {
    while (c > b && b < b_target) {
      --c;
      ++b;
    }
    ++b_target;
    while (b - a > 2) {
      --b;
      ++a;
      if (std::pow(a, 2) + std::pow(b, 2) == std::pow(c, 2)) {
        return {a, b, c};
      }
    }
    c += a - 1;
    a = 1;
    std::cout << a << ' ' << b << ' ' << c << '\n';
  }
}
