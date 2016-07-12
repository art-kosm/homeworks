findTheGreater :: [Int] -> Maybe Int
findTheGreater [] = fail ""
findTheGreater [f] = return f
findTheGreater (f:s:list) = if f > s then return f else find list f s

find :: [Int] -> Int -> Int -> Maybe Int
find [] f s = if s > f then return s else fail ""
find (t:list) f s = if s > f && s > t then return s else find list s t