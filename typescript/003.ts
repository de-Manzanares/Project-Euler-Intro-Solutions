/**
 *  https://projecteuler.net/problem=3
 *  The prime factors of 13195 are 5, 7, 13 and 29.
 *  What is the largest prime factor of the number 600851475143?
 */


function largest_prime_factor(n: number) {
  let i = 3;
  while (n % 2 === 0) {
    n /= 2;
  }
  if (n === 1) {
    return 2;
  }
  while (n !== 1) {
    while (n % i === 0) {
      n /= i;
    }
    i += 1;
  }
  i -= 1;
  return i;
}

console.log(largest_prime_factor(600851475143));
