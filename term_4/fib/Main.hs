fib x = if x < 3 then 1 else (fib (x - 2) + fib (x - 1))

main = do
    var <- getLine
    putStrLn (show (fib (read var :: Int)))