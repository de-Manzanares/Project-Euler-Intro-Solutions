{-
    https://projecteuler.net/problem=3
    The prime factors of 13195 are 5, 7, 13 and 29.
    What is the largest prime factor of the number 600851475143?
-}

-- | Divides out all 2's
evenPrime :: Integer -> Integer
evenPrime n
  | even n = evenPrime (n `div` 2)
  | otherwise = n

-- | Finds the largest prime factor
oddPrimes :: Integer -> Integer
oddPrimes n = go 3 n
  where
    go i n
      | n == 1 = if i == 3 then 2 else i
      | n `mod` i == 0 = go i (n `div` i)
      | otherwise = go (i + 2) n

f :: Integer -> Integer
f n = oddPrimes (evenPrime n)

main :: IO ()
main = print (f 600851475143)
