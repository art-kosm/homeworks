import System.IO
import Control.Monad.Writer

data Graph v e = Graph [(Int, v)] [(Int, Int, e)]
data Vertex = Vertex {num :: Int, distance :: Int, previous :: Int, visited :: Bool}
data Edge = Edge {leftEnd :: Int, rightEnd :: Int, weight :: Int}
data DijkstraGraph = DijkstraGraph [Vertex] [Edge]

inf :: Int
inf = maxBound :: Int

findTheShortestPath :: Graph v Int -> Int -> Int -> IO ()
findTheShortestPath g first last = putStrLn $ useDijkstrasAlgorithm (convert g first) last

convert :: Graph v Int -> Int -> DijkstraGraph
convert (Graph vl el) first = DijkstraGraph (convertVertexes first vl) (convertEdges el)

convertVertexes :: Int -> [(Int, v)] -> [Vertex]
convertVertexes first = map (\v -> Vertex {
  num = fst v,
  distance = if fst v == first then 0 else inf,
  previous = -1,
  visited = False}) 

convertEdges :: [(Int, Int, Int)] -> [Edge]
convertEdges = map (\(f, t, w) -> Edge {leftEnd = f, rightEnd = t, weight = w})

useDijkstrasAlgorithm :: DijkstraGraph -> Int -> String
useDijkstrasAlgorithm = visitNext

visitNext :: DijkstraGraph -> Int -> String
visitNext g@(DijkstraGraph vl el) last = let closest = findClosestUnvisited vl (head vl)
  in if num closest == last 
       then let wr = runWriter (retrievePath last vl) in fst wr ++ show (reverse (snd wr))
       else visitNext (updateNeighbours g el closest) last

findClosestUnvisited :: [Vertex] -> Vertex -> Vertex
findClosestUnvisited [] closest = closest
findClosestUnvisited (v:vl) closest 
 | visited closest || 
   not (visited v) && distance v < distance closest  = findClosestUnvisited vl v
 | otherwise                                         = findClosestUnvisited vl closest

retrievePath :: Int -> [Vertex] -> Writer [Int] String
retrievePath (-1) _ = return []
retrievePath last vl = do
  tell [last]
  let prev = findPrev last vl
  rest <- retrievePath prev vl
  return "The shortest path is "

findPrev :: Int -> [Vertex] -> Int
findPrev n (v:vl) = if num v == n then previous v else findPrev n vl

updateNeighbours :: DijkstraGraph -> [Edge] -> Vertex -> DijkstraGraph
updateNeighbours (DijkstraGraph vl el) [] cur = 
  DijkstraGraph (map (\v -> v {visited = if num v == num cur then True else visited v}) vl) el
updateNeighbours g@(DijkstraGraph vl el) (edge:tail) cur = 
  if leftEnd edge == num cur
    then updateNeighbours (DijkstraGraph (map (updateVertex edge cur) vl) el) tail cur
    else updateNeighbours g tail cur

updateVertex :: Edge -> Vertex -> Vertex -> Vertex
updateVertex e c v = let newDistance = distance c + weight e 
  in if rightEnd e == num v && (newDistance < distance v) 
       then v {distance = newDistance, previous = num c} 
       else v
