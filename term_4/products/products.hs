getProducts :: Int -> [Int]
getProducts n = take n [1..] >>= 
                \x -> take n [1..] >>=
                \y -> return (x * y)