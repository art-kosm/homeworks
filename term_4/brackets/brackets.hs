check_brackets :: String -> Bool
check_brackets = brackets "_"

brackets :: String -> String -> Bool
brackets "_" "" = True
brackets  _  "" = False
brackets (s:stack) (c:string) | c == '(' || c == '[' || c == '{'  = brackets (c:s:stack) string
                              | (c == ')' && s == '(') || 
                                (c == ']' && s == '[') || 
                                (c == '}' && s == '{')             = brackets stack string
                              | (c == ')' && s /= '(') || 
                                (c == ']' && s /= '[') || 
                                (c == '}' && s /= '{')             = False  
                              | otherwise                          = brackets (s:stack) string