t = int(input())
while(t):
  n,q = list(map(int,input().strip().split()))
  lis = list(map(int,input().strip().split()))
  lis.sort(reverse = True)
  for i in range(q):
    ans = 0
    inp = int(input())
    for i in range(n):
      if (lis[i]>=inp):
        ans+=1
        break
      else:
        inp = inp - lis[i]
        ans+=1
    else:
      ans = -1
    print(ans)
  t-=1