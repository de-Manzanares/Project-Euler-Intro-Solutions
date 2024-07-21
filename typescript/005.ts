/**
 * <p>$2520$ is the smallest number that can be divided by each of the numbers
 * from $1$ to $10$ without any remainder.</p> <p>What is the smallest positive
 * number that is <strong class="tooltip">evenly divisible<span
 * class="tooltiptext">divisible with no remainder</span></strong> by all of the
 * numbers from $1$ to $20$?</p>
 */

function divisible_by_all_to_ceiling(ceiling: number): number {
  function bool_helper(n: number): boolean {
    for (let i: number = ceiling; i > 0; --i) {
      if (n % i !== 0) {
        return false;
      }
    }
    return true;
  }

  let i: number = ceiling * (ceiling - 1);
  while (!bool_helper(i)) {
    ++i;
  }
  return i;
}

console.log(divisible_by_all_to_ceiling(20));
