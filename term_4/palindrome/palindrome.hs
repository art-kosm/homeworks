palindrome :: Eq a => [a] -> Bool
palindrome list = check list (reverse list)

check :: Eq a => [a] -> [a] -> Bool
check [] [] = True
check _ [] = False
check [] _ = False
check (x:list1) (y:list2) = if x == y
                            then check list1 list2
                            else False
