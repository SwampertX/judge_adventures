readInput = (map read) . words

main = interact (writeOutput . solve . readInput)

solve [] = []
solve (a:b:rest) = abs(a - b):(solve rest)

writeOutput = unlines . (map show)
