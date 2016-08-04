data BinarySearchTree a = Null
                          | Leaf a
                          | Branch (BinarySearchTree a) a (BinarySearchTree a)

addIn :: (Eq a, Ord a) => BinarySearchTree a -> a -> BinarySearchTree a
addIn (Null) i = Leaf i
addIn (Leaf e) i | i > e   = Branch (Null) e (Leaf i)
                 | i == e  = Leaf e
                 | i < e   = Branch (Leaf i) e (Null)
addIn (Branch t1 e t2) i | i > e   = Branch t1 e (addIn t2 i)
                         | i == e  = Branch t1 e t2
                         | i < e   = Branch (addIn t1 i) e t2

removeFrom :: (Eq a, Ord a) => BinarySearchTree a -> a -> BinarySearchTree a
removeFrom (Null) _ = Null
removeFrom (Leaf e) i = if e == i then Null else Leaf e
removeFrom (Branch t1 e t2) i | i > e   = removeFakeBranches $ Branch t1 e (removeFrom t2 i)
                              | i == e && isNull t1 && (not $ isNull t2)
                                        = t2
                              | i == e && (not $ isNull t1) && isNull t2
                                        = t1
                              | i == e  = Branch t1 (leftmost t2) (removeLeftmost t2)
                              | i < e   = removeFakeBranches $ Branch (removeFrom t1 i) e t2

removeFakeBranches :: BinarySearchTree a -> BinarySearchTree a
removeFakeBranches (Branch Null e Null) = Leaf e
removeFakeBranches (Branch t1 e t2) = Branch (removeFakeBranches t1) e (removeFakeBranches t2)
removeFakeBranches t = t

isNull :: BinarySearchTree a -> Bool
isNull (Null) = True
isNull _ = False

leftmost :: BinarySearchTree a -> a
leftmost (Leaf e) = e
leftmost (Branch Null e _) = e
leftmost (Branch t1 e _) = leftmost t1

removeLeftmost :: BinarySearchTree a -> BinarySearchTree a
removeLeftmost (Leaf _) = Null
removeLeftmost (Branch Null e t2) = t2
removeLeftmost (Branch t1 e t2) = Branch (removeLeftmost t1) e t2

contains :: Eq a => BinarySearchTree a -> a -> Bool
contains (Null) _ = False
contains (Leaf e) i = e == i
contains (Branch t1 e t2) i = e == i || contains t1 i || contains t2 i

size :: BinarySearchTree a -> Int
size (Null) = 0
size (Leaf _) = 1
size (Branch t1 _ t2) = 1 + size t1 + size t2

height :: BinarySearchTree a -> Int
height (Null) = 0
height (Leaf _) = 1
height (Branch t1 _ t2) = 1 + max (height t1) (height t2)

showTree :: Show a => BinarySearchTree a -> String
showTree (Null) = ""
showTree (Leaf e) = show e
showTree (Branch t1 e t2) = "(" ++ showTree t1 ++ ") " ++ show e ++ " (" ++ showTree t2 ++ ")"
