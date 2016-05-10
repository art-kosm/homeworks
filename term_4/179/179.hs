sec :: [Int]
sec = 1 : 7 : 9 : secTail where 
          lastDigits = map (`mod` 10) sec
          tripleSec = (>>= replicate 3) sec
          secTail = zipWith (\x y -> 10 * x + y) tripleSec lastDigits
