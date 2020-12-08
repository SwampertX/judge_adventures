from itertools import permutations

n, k = [int(i) for i in input().strip().split()]
adjMat = [[int(i) for i in input().strip().split()] for _ in range(n)]
# print(adjMat)

counter = 0
for perm in permutations([i for i in range(2, n + 1)]):
    perm = (1,) + perm + (1,)
    weight = 0
    for i in range(len(perm) - 1):
        weight += adjMat[perm[i] - 1][perm[i + 1] - 1]
    if weight == k:
        counter += 1
print(counter)
