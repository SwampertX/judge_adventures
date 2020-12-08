import qualified Text.Parsec as P
import Data.Either(fromRight)

-- main = interact $ print . solve . input

-- solve :: [String] -> Integer
-- solve unparsed =
--   length . (filter isLegal) parsed
--   where
--     parsed = P.parse 
--     -- parses a line
--     lineP = do
--       minOccurs <- intP
--       dashP
--       maxOccurs <- intP
--       P.spaces
--       letter <- P.letter
--       colonP
--       password <- passwordP
--       return (minOccurs, maxOccurs, letter, password)
--     passwordP = P.many1 P.letter
--     intP = read <$> P.many1 P.digit
--     dashP = void $ P.char '-'
--     colonP = void $ P.char ':'

isLegal (low, high, char, str) = True
occ (char,str) = length $ filter (char ==) str

data Password = Password {
  m :: Int,
  n :: Int,
  c :: Char,
  p :: String
                         } deriving (Show)

countChar :: Char -> String -> Int
countChar c p = length $ filter (== c) p

isIn :: Int -> (Int, Int) -> Bool
isIn a (b, c) = (b <= a) && (a <= c)

isValid :: Password -> Bool
-- isValid (Password m n c p) = (countChar c p) `isIn` (m, n)
isValid (Password m n c p) =
  left /= right
  where
    left = m > (length p) || p !! (m-1) == c
    right = n > (length p) || p !! (n-1) == c

-- Type is Parsec s () a; parses type s in to type a
passwordParser :: P.Parsec String () Password
passwordParser = do
  m <- P.many P.digit
  P.char '-'
  n <- P.many P.digit
  P.spaces
  c <- P.letter
  P.char ':'
  P.spaces
  p <- P.many P.letter
  return $ Password (read m :: Int) (read n :: Int) c p

parsePassword :: String -> Password
parsePassword pswd = fromRight (error "Parsing error") (P.parse passwordParser "" pswd)

-- takes in all the lines and return the num of valid lines
solve1 :: [String] -> Int
solve1 records = do
  length $ filter (isValid . parsePassword) records

main :: IO()
main = do
  inp <- readFile "day2.in"
  print $ (solve1 . lines) inp
