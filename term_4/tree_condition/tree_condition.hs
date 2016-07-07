data Tree a = Leaf a
              | Branch (Tree a) a (Tree a) 

take_if :: (a -> Bool) -> Tree a -> [a]
take_if condition tree = get_list condition tree []

get_list :: (a -> Bool) -> Tree a -> [a] -> [a]
get_list condition (Leaf x) acc = if condition x then (x:acc) else acc
get_list condition (Branch t1 x t2) acc = if condition x then (x:list) else list
                                          where list = get_list condition t1 (get_list condition t2 acc)

fold :: (a -> b -> b) -> b -> Tree a -> b
fold operation initial tree = foldr operation initial (take_if (return True) tree)