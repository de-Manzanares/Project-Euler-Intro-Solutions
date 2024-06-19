#=
    https://projecteuler.net/problem=3
    The prime factors of 13195 are 5, 7, 13 and 29.
    What is the largest prime factor of the number 600851475143?
=#

function f(n)
    while iseven(n)         # there is only one even prime :)
        n /= 2
    end

    if n == 1               # if the given number is a power of 2
        return 2            # 2 is the largest prime factor
    end

    i = 3
    while n != 1
        while n % i == 0    # while i evenly divides n
            n /= i          # n = n/i
        end
        i += 2              # move to next odd number (there is only one even prime)
    end

    i -= 2                  # account for extra increment after exiting the while loop

    return i
end

println(f(32))
