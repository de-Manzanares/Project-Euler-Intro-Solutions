# https://projecteuler.net/problem=3
# <p>The prime factors of $13195$ are $5, 7, 13$ and $29$.</p>
# <p>What is the largest prime factor of the number $600851475143$?</p>

i = 3
n = 600851475143

while n % 2 == 0:
    n /= 2

if n == 2:
    print(2)

while n != 1:
    while n % i == 0:
        n /= i
    i += 1
i -= 1

print(i)
