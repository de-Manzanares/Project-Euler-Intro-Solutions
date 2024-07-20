# https://projecteuler.net/problem=4
# <p>A palindromic number reads the same both ways. The largest palindrome made
# from the product of two $2$-digit numbers is $9009 = 91 \times 99$.</p>
# <p>Find the largest palindrome made from the product of two $3$-digit numbers

i = 100 ** 2
j = 999 ** 2

nums = [0, 0, 0]

while i < j:
    if str(i) == str(i)[::-1]:
        for k in range(100, 1000):
            if i % k == 0 and i / k < 1000:
                nums = [i, k, i / k]
                break
    i += 1

print(nums)
