t = int(input())
while(t):
    n = int(input())
    per = list(map(int,input().strip().split()))
    for i in per:
        per.append(per.pop(0)-1)
    for i in range(n):
        x = i
        count = 1
        while(per[x]!=i):
            x = per[x]
            count+=1
        print(count,end=" ")
    print()
    t-=1