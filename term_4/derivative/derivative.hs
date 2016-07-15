import System.IO 

data Expression = Expression {positiveDegree       :: Int,
                              negativeDegree       :: Int,
                              positiveCoefficients :: [Float],
                              negativeCoefficients :: [Float]
                             }

printDerivative :: String -> IO ()
printDerivative s = putStrLn $ simplify $ showExpression $ differentiate $ getExpression 
                    (getSummands (getTokens s) [] []) (Expression {positiveDegree = 0, 
                                                                   negativeDegree = 0, 
                                                                   positiveCoefficients = [0, 0..], 
                                                                   negativeCoefficients = [0, 0..]})

getTokens :: String -> [String]
getTokens s = tokenize s [] (-1)

tokenize :: String -> [String] -> Int -> [String]
tokenize [] r n = reverse $ if n >= 0 then ((show n):r) else r
tokenize (x:s) r n | x == '+' || x == '-' || 
                     x == '*' || x == '/'     = tokenize s (if n >= 0 then ([x]:(show n):r) else ([x]:r)) (-1)
                   | x == 'x'                 = tokenize s (if n >= 0 then ("x":(show n):r) else ("x":r)) (-1)
                   | (-1) < i && i < 10       = tokenize s r (if n >= 0 then (10 * n + i) else i)
                   | otherwise                = tokenize s r n
                   where list = reads [x] :: [(Int, String)]
                         i    = if not (null list) then fst $ head list else -1

getSummands :: [String] -> [String] -> [[String]] -> [[String]]
getSummands [] s summands = reverse ((reverse s):summands)
getSummands (t:tokens) s summands = if t == "+" || t == "-" then getSummands tokens [t] ((reverse s):summands)
                                                            else getSummands tokens (t:s) summands

getExpression :: [[String]] -> Expression -> Expression
getExpression [] currentExpression = currentExpression
getExpression (s:summands) currentExpression = 
  getExpression summands (updateExpression currentExpression (includeSummand s "" 1 0))

includeSummand :: [String] -> String -> Float -> Int -> (Float, Int)
includeSummand [] last c p = (c, p)
includeSummand (f:factors) last c p | f == "-"  = includeSummand factors f (-c) p
                                    | f == "x"  = includeSummand factors f c 
                                                    (if last == "/" then p - 1 else p + 1)
                                    | f == "0"  = includeSummand factors f 
                                                    (if last == "/" then c / 0 else c * 0) p
                                    | i /= 0    = includeSummand factors f 
                                                    (if last == "/" then c / i else c * i) p
                                    | otherwise  = includeSummand factors f c p
                                    where list = reads f :: [(Float, String)]
                                          i    = if not $ null list then fst $ head list else 0

updateExpression :: Expression -> (Float, Int) -> Expression
updateExpression e (c, p) = if p >= 0 
  then let coeffs = positiveCoefficients e
           deg = positiveDegree e
       in e {positiveCoefficients = modify coeffs [] (c + coeffs !! p) p,
             positiveDegree = if p > deg then p else deg}
  else let coeffs = negativeCoefficients e
           deg = negativeDegree e
       in e {negativeCoefficients = modify coeffs [] (c + coeffs !! (-p - 1)) (-p - 1),
             negativeDegree = if p < deg then p else deg}

modify :: [Float] -> [Float] -> Float -> Int -> [Float]
modify list [] _ (-1) = list
modify (x:list) tempList newValue pos | pos > 0   = modify list (x:tempList) newValue (pos - 1) 
                                      | pos == 0  = modify (newValue:list) tempList 0 (-1)
                                      | pos < 0   = modify ((head tempList):x:list) (tail tempList) 0 (-1)

differentiate :: Expression -> Expression
differentiate e = let pos = positiveDegree e
                      neg = negativeDegree e
                      posCoef = tail $ take (pos + 1) (positiveCoefficients e)
                      negCoef = take (-neg) (negativeCoefficients e)
                  in Expression {positiveDegree = if pos > 0 then pos - 1 else 0,
                                 negativeDegree = if neg < 0 then neg - 1 else 0,
                                 positiveCoefficients = zipWith (*) posCoef [1..],
                                 negativeCoefficients = (0:(zipWith (*) negCoef [-1, -2..]))}

showExpression :: Expression -> String
showExpression e = (concatMap (showSummand) $ take (positiveDegree e + 1) $ 
                    zip (positiveCoefficients e) [0..]) ++ (concatMap (showSummand) $ 
                    take (-(negativeDegree e)) $ zip (negativeCoefficients e) [-1, -2..])

showSummand :: (Float, Int) -> String
showSummand (c, p) | c == 0  = ""
                   | p > 1  && c == 1  = "+" ++ take p ['x','x'..]
                   | p >= 0 && c > 0   = "+" ++ show c ++ take p ['x','x'..]
                   | p >= 0 && c < 0   = show c ++ take p ['x','x'..]
                   | p < 0  && c > 0   = "+" ++ show c ++ showNegativeDegrees p
                   | p < 0  && c < 0   = show c ++ showNegativeDegrees p

showNegativeDegrees :: Int -> String
showNegativeDegrees p = concatMap (\(a, b) -> [a, b]) (zip (take (-p) ['/', '/'..]) (take (-p) ['x', 'x'..]))

simplify :: String -> String
simplify (' ':res) = simplify res
simplify ('+':res) = simplify res
simplify res = removeExcessiveFractions res ""

removeExcessiveFractions :: String -> String -> String
removeExcessiveFractions [] (s:t:rest) = if [t, s] == ".0" then reverse rest else reverse (s:t:rest)
removeExcessiveFractions [] rest = reverse rest
removeExcessiveFractions (c:string) (s:t:rest) = if [t, s] == ".0" && all (/= c) (take 10 ['0'..]) 
  then removeExcessiveFractions (c:string) rest
  else removeExcessiveFractions string (c:s:t:rest)
removeExcessiveFractions (c:string) rest = removeExcessiveFractions string (c:rest)