t = int(input())
for tt in range(t):
    n = int(input())
    m = [[0 for _ in range(n)] for _ in range(n)]
    row,col=0,0
    for i in range(n):
        m[i] = [int(k) for k in input().split(' ')]
        row += n - len(set(m[i])) > 0
    for i in range(n): #col
        currcol = [m[j][i] for j in range(n)]
        col += n-len(set(currcol)) > 0
    trace = sum([m[i][i] for i in range(n)])
    print("Case #{}: {} {} {}".format(tt+1,trace,row,col))
