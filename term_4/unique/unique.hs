import Data.List
all_unique :: (Num a, Ord a) => [a] -> Bool
all_unique list = length (filter (== 0) $ zipWith (-) sorted $ tail sorted) == 0
                  where sorted = sort list
