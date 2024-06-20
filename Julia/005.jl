#=
    https://projecteuler.net/problem=5
    2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
    What is the smallest positive number that is evenly divisible (divisible with no remainder) by all of the numbers 
    from 1 to 20?
=#

function p5a()
    i = 20 * 19

    while true
        d = 20

        while i % d == 0
            d -= 1
            if d == 1
                return i
            end
        end

        i += 1
    end
end

function p5b()
    function lcm(a, b)
        return abs(a * b) ÷ gcd(a, b)
    end

    result = 1

    for i in 2:20
        result = lcm(result, i)
    end

    return result
end
