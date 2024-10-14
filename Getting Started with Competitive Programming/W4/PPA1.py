n = int(input())
lis= []
for i in range(n):
    q = list(map(int,input().strip().split()))
    if (q[0]==1):
        lis.append(q[1])
    else:
        for i in range(len(lis)):
            if lis[i] == q[1]:
                lis[i] = q[2]
for i in lis:
    print(i,end=" ")
print()