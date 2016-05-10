max_neighbours :: [Int] -> Int
max_neighbours list = neighbours list 1 1 minBound

neighbours :: [Int] -> Int -> Int -> Int -> Int
neighbours [] _ _ _ = 0
neighbours [a] _ max_pos _ = max_pos
neighbours (x:list) cur_pos max_pos max_sum = if x + head list > max_sum 
                                              then neighbours list (cur_pos + 1) cur_pos (x + head list)
                                              else neighbours list (cur_pos + 1) max_pos max_sum
