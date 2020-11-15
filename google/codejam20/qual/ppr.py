t = int(input())
for tt in range(1,t+1):
    n = int(input())
    j = [True for _ in range(24*60+1)]
    c = [True for _ in range(24*60+1)]
    res = ""
    for _ in range(n):
        start,end = [int(k) for k in input().split(' ')]
        if res=="IMPOSSIBLE":
            continue
        jcan = True
        ccan = True
        for i in range(start,end):
            jcan = j[i] and jcan
            ccan = c[i] and ccan
            if not jcan and not ccan:
                break
        if not jcan and not ccan:
            res="IMPOSSIBLE"
            continue
        if jcan:
            res += 'J'
            for i in range(start,end):
                j[i] = False
        else:
            res += 'C'
            for i in range(start,end):
                c[i] = False
    print("Case #{}: {}".format(tt,res))
