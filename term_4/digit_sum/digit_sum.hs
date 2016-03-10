sum' :: Int -> Int
sum' 0 = 0
sum' n = n `mod` 10 + sum' (n `div` 10)