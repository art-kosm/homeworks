count_even1 :: [Int] -> Int
count_even1 list = length $ filter (even) list

count_even2 :: [Int] -> Int
count_even2 list = foldr ((+) . (1 -) . (`mod` 2)) 0 list

count_even3 :: [Int] -> Int
count_even3 list = foldr (+) 0 $ map ((1 - ) . (`mod` 2)) list