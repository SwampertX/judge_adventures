-- part1 :: [String] -> Int
-- part1 rows = snd $ foldl folder (1,0) rows

-- folder :: (Int, Int) -> String -> (Int, Int)
-- folder (rowCount, cnt) row =
--   if isTree then (rowCount + 1, cnt + 1) else (rowCount + 1, cnt)
--   where
--     isTree = '#' == row !! mod (rowCount * 3) rowLen
--     rowLen = length row

-- main :: IO()
-- main = do
--   inp <- readFile "day3.in"
--   (print.part2.lines) inp

-- Below is Part 2
-- pdt :: [Int] -> Int
-- pdt lst = foldl1 (\x -> \y -> x*y) lst

toCheck :: [(Int, Int)]
toCheck = [(1,1), (3,1), (5,1), (7,1), (1,2)]
-- toCheck = [(3,1)]

-- now the helper structure: (mult, count, )
part2 :: [String] -> Int
part2 rows = product $ map (\x -> checker x rows) toCheck

-- when counter is == down, check if multiplier * right is #, if so count ++
data Helper = Helper {
  multiplier :: Int,
  count :: Int,
  counter :: Int,
  right :: Int,
  down :: Int}
  
-- counter takes in (right, down) and a map before returning the
-- number of trees '#' met.
checker :: (Int, Int) -> [String] -> Int
-- recall: fold init binary lst
-- counter here is 0
checker (r, d) rows = count $ foldl folder Helper{multiplier=1,count=0,counter=0,right=r,down=d} rows

folder :: Helper -> String -> Helper
folder Helper{multiplier=m,count=c,counter=cc,right=r,down=d} row =
  Helper{multiplier=newm,count=newc,counter=newcc,right=r,down=d}
  where
    newm = if cc == d then m + 1 else m
    newc = if cc == d && isTree then c+1 else c
    newcc = if cc == d then 1 else cc + 1
    isTree = '#' == row !! mod (m * r) rowLen
    rowLen = length row
      
main :: IO()
main = do
  inp <- readFile "day3.in"
  (print.part2.lines) inp
