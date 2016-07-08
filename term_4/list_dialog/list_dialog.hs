import System.IO

main = mainLoop []

mainLoop :: [Int] -> IO()
mainLoop list = do
  input <- inputLine "> Command: "
  (newList, continue) <- processInput input list
  if continue
    then mainLoop newList
    else return ()

inputLine :: String -> IO String
inputLine input = do
  putStr input
  getLine

processInput :: String -> [Int] -> IO ([Int], Bool)
processInput input list | input == "0"  = return (list, False)
                        | input == "1"  = do
                                            input <- inputLine "> Enter the number: "
                                            return (add list (read input :: Int) [], True)
                        | input == "2"  = do
                                            input <- inputLine "> Enter the number: "
                                            return (remove list (read input :: Int) [], True)
                        | input == "3"  = do
                                            putStrLn $ "> "++ show list
                                            return (list, True)
                        | otherwise     = do
                                            putStrLn "> Unknown command"
                                            return (list, True)

add :: [Int] -> Int -> [Int] -> [Int]
add [] value start = reverse (value:start)
add (h:list) value start | value > h   = add list value (h:start)
                         | value <= h  = reverse start ++ (value:h:list)

remove :: [Int] -> Int -> [Int] -> [Int]
remove [] _ start = reverse start
remove (h:list) value start | value > h   = remove list value (h:start)
                            | value == h  = reverse start ++ list
                            | value < h   = reverse start ++ (h:list)