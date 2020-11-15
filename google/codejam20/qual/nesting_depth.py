t = int(input())
for tt in range(1,t+1):
    s = input()
    print("Case #{}: ".format(tt),end='')
    curr = 0
    for c in s:
        c = int(c)
        if c > curr: # op3n
            print('('*(c-curr),end='')
        else:
            print(')'*(curr-c),end='')
        print(c,end='')
        curr=c
    print(')'*curr)
