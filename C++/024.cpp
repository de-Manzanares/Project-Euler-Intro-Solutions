/*
 * <p>A permutation is an ordered arrangement of objects. For example, 3124 is
 * one possible permutation of the digits 1, 2, 3 and 4. If all of the
 * permutations are listed numerically or alphabetically, we call it
 * lexicographic order. The lexicographic permutations of 0, 1 and 2 are:</p>
 * p class="center">012   021   102   120   201   210</p>
 * <p>What is the millionth lexicographic permutation of the digits 0, 1, 2, 3,
 * 4, 5, 6, 7, 8 and 9?</p>
 */

#include <algorithm>
#include <iostream>
#include <thread>
#include <vector>

bool is_a_permutation(unsigned long const i) {
  std::string const str = std::to_string(i);
  std::vector<int> digits(10);
  for (auto const &ch : str) {
    if (std::isdigit(ch)) {
      ++digits[ch - '0'];
    } else {
      return false;
    }
  }
  if (str.size() < 10 && digits[0] == 0) {
    digits[0] = 1;
  }
  if (!std::ranges::all_of(digits, [](int const n) { return n == 1; })) {
    return false;
  }
  return true;
}

// template <typename T>
// [[noreturn]] void incremental_print(T &value, int const sleep_seconds) {
//   while (true) {
//     std::cout << value;
//     std::this_thread::sleep_for(std::chrono::seconds(sleep_seconds));
//   }
// }

int counter{};

// much easier (for the programmer) than making some complicated mechanism to
// generate ONLY numers consisting of 1 character each of 0-9, just iterate
// through the numbers one by one (lol) and detect if it is one of the
// permutations we are looking for.
int main() {
  // std::thread incremental_print_thread(incremental_print<int>, counter, 1);
  for (unsigned long i = 123456789; i < 9876543210 + 1; ++i) {
    if (is_a_permutation(i)) {
      ++counter;
    }
    if (i % 100'000'000 == 0) {
      std::cout << 100 * static_cast<double>(counter) / 1'000'000
                << " % complete" << '\n';
    }
    if (counter == 1'000'000) {
      std::cout << i;
      break;
    }
  }
  // incremental_print_thread.join();
}
