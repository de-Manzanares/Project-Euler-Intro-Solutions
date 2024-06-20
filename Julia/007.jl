#=
    https://projecteuler.net/problem=7
    By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
    What is the 10,001st prime number
=#

function p7a()
    n = 3
    count = 1
    primes = [2]

    while count < 10_001
        all(n % p != 0 for p ∈ primes) ? (push!(primes, n); n += 1; count += 1) : (n += 1)
    end
    return (primes[end])
end

function p7b()
    n = 3
    count = 1
    primes = [2]

    while count < 10_001
        if all(n % p != 0 for p ∈ primes if p ≤ sqrt(n))
            push!(primes, n)
            count += 1
        end
        n += 2
    end
    return (primes[end])
end
