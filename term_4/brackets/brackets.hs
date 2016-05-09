check_brackets :: String -> Bool
check_brackets s = brackets s 0

brackets :: String -> Int -> Bool
brackets [] 0 = True
brackets [] _ = False
brackets (c:s) (-1) = False
brackets (c:s) n | c == '('   = brackets s (n + 1)
                 | c == ')'   = brackets s (n - 1)
                 | otherwise  = brackets s n