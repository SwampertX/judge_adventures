import Data.Maybe
import Data.List

main :: IO()
main = interact (printOutput . part2 . readInput)

readInput :: String -> [Integer]
readInput = (map read) . words

printOutput :: [Integer] -> String
printOutput = unlines . (map show)

-- part1 :: [Integer] -> [Integer]
-- part1 ls =
--     [ls !! l1 * ls !! l2]
--     where
--         len = length ls
--         index = fromJust (elemIndex 2020 (concatMap (\x -> map (x +) ls) ls))
--         (l1, l2) = quotRem index len

part1 :: [Integer] -> [Integer]
part1 ls =
  ((map (\x -> (fst x) * (snd x))). (filter (\x -> (fst x) + (snd x) == 2020))) pairs
  where
    pairs = [(x,y)|(x:rest) <- tails ls, y <- rest]


part2 :: [Integer] -> [Integer]
part2 ls =
  ((map (\x -> product x )). (filter (\x -> sum x == 2020))) triples
  where
    triples = [[a,b,c]|(a:rest) <- tails ls, (b:restb) <- tails rest, c <- restb]
