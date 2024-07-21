/**
 * <p>A palindromic number reads the same both ways. The largest palindrome made
 * from the product of two $2$-digit numbers is $9009 = 91 \times 99$.</p>
 * <p>Find the largest palindrome made from the product of two $3$-digit
 * numbers.</p>
 */

function largest_palindrome(): number[] {
  let nums: number[] = Array(3);

  function is_palindrome(n: number): boolean {
    return n.toString() === (n.toString()).split('').reverse().join('');
  }

  for (let i: number = 100 ** 2; i < 999 ** 2; ++i) {
    if (is_palindrome(i)) {
      for (let j: number = 100; j < 1000; ++j) {
        if (i % j === 0 && i / j < 1000) {
          nums = [j, i / j, i];
        }
      }
    }
  }
  return nums;
}

console.log(largest_palindrome());
