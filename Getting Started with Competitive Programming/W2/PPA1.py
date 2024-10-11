t=int(input())
while(t):
  n,x = list(map(int,input().strip().split()))
  lis = list(map(int,input().strip().split()))
  lis.sort()
  for i in range(n):
    if (lis[n+i]-lis[i] < x):
      print("NO")
      break
  else:
    print("YES")
  t-=1