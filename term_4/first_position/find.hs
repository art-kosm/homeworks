find :: Int -> [Int] -> Int
find item list = search item list 1

search :: Int -> [Int] -> Int -> Int
search _ [] _ = -1
search item (x:list) counter = if x == item 
                               then counter
                               else search item list (counter + 1)