data Tree a = Leaf a
              | Branch (Tree a) a (Tree a) 

height :: Tree a -> Int
height (Leaf _) = 1
height (Branch t1 _ t2) = 1 + max (height t1) (height t2)

min_distance :: Tree a -> Int
min_distance (Leaf _) = 1
min_distance (Branch t1 _ t2) = 1 + min (min_distance t1) (min_distance t2)