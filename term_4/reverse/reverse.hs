match :: ([a], [a]) -> ([a], [a])
match (list, [x]) = (x:list, [])
match (x:xs, []) = match ([x], xs)
match (y, x:xs) = match (x : y, xs)

reverse' :: [a] -> [a]
reverse' list = fst (match (list, []))
