data Polynome = Polynome {coefficients :: [Int]}

add :: Polynome -> Polynome -> Polynome
add p q = let cp = coefficients p
              cq = coefficients q
              difference = length cp - length cq
          in Polynome {coefficients = if difference > 0 
                                        then zipWith (+) cp (cq ++ take difference [0, 0..])
                                        else zipWith (+) (cp ++ take (-difference) [0, 0..]) cq}

mul :: Polynome -> Polynome -> Polynome
mul p q = if coefficients p /= [] 
            then addNextDegree p q 0
            else Polynome {coefficients = []}

addNextDegree :: Polynome -> Polynome -> Int -> Polynome
addNextDegree p q k = let cp = coefficients p
  in if cp /= [] 
       then add Polynome {coefficients = map (* (head cp)) (take k [0, 0..] ++ coefficients q)} 
                (addNextDegree (Polynome {coefficients = tail cp}) q (k + 1))
       else Polynome {coefficients = []}

showPolynome :: Polynome -> String
showPolynome p = fix $ showNextDegree (coefficients p) 0

showNextDegree :: [Int] -> Int -> String
showNextDegree [] _ = ""
showNextDegree (c:cp) k | c == 0     = showNextDegree cp (k + 1)
                        | k == 0     = show c ++ showNextDegree cp (k + 1)
                        | otherwise  = (if c > 0 
                                          then " + " ++ (if c /= 1 then show c else "") 
                                          else " - " ++ (if c /= -1 then show (-c) else "")) ++ 
                                       (if k == 1 then "x" else "x^" ++ show k) ++ 
                                       showNextDegree cp (k + 1)

fix :: String -> String
fix "" = "0"
fix (' ':p) = fix p
fix ('+':p) = fix p
fix ('-':p) = ('-':(tail p))
fix p = p