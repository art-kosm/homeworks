fact :: Int -> Int
fact x = if x == 0 then 1 else x * fact (x - 1)

main :: IO ()
main = do
    var <- getLine
    putStrLn (show (fact (read var :: Int)))
