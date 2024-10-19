t = int(input())
while(t):
  n,q = list(map(int,input().strip().split()))
  lis = list(map(int,input().strip().split()))
  ans = 0
  for _ in range(q):
    i,j = list(map(int,input().strip().split()))
    for x in range(n):
      if lis[x] == i:
        for y in range(x,n):
          if lis[y] == j:
            ans += 1
            break
        break
  
  print(ans)
  t-=1