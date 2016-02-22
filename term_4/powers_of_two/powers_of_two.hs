power :: Int -> [Int]
power n = addPower 2 n

addPower :: Int -> Int -> [Int]
addPower initial 0 = []
addPower initial n = initial : addPower (initial * 2) (n - 1)
