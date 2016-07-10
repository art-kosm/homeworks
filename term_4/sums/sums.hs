import System.IO

showSums :: Int -> IO ()
showSums n = setFirstSummand n 1

setFirstSummand :: Int -> Int -> IO ()
setFirstSummand n first = if first <= n
  then getNextRepresentation (take (n - first + 1) $ first:[1, 1..]) n 0
  else return ()

getNextRepresentation :: [Int] -> Int -> Int -> IO ()
getNextRepresentation (first:summands) n position = 
  let actualSummands = take (n - first - position + 1) (first:summands)
  in if ((foldr (+) 0 actualSummands) == n)
       then do
         showSum actualSummands
         getNextRepresentation (increase actualSummands) n (position + 1)
       else setFirstSummand n (first + 1)

increase :: [Int] -> [Int]
increase (h:list) = increaseFirst h list []

increaseFirst :: Int -> [Int] -> [Int] -> [Int]
increaseFirst h [] start = h:(reverse start)
increaseFirst h (f:list) start = if f < h 
  then h:((reverse start) ++ ((f + 1):list))
  else increaseFirst h list (f:start)

showSum :: [Int] -> IO ()
showSum (s1:s2:sum) = do
  putStr $ (show s1) ++ " + "
  showSum $ s2:sum
showSum [s] = do
  putStr $ (show s) ++ "\n"
  return ()