t = int(input())
while(t):
  n = int(input())
  lis1 = list(map(int,input().strip().split()))
  m = int(input())
  lis2 = list(map(int,input().strip().split()))
  lis1.sort()
  lis2.sort()
  if lis1[-1]==lis2[-1]:
    print("Ankita")
    print("Biswas")
  elif (lis1[-1]<lis2[-1]):
    print("Biswas")
    print("Biswas")
  else:
    print("Ankita")
    print("Ankita")
  t-=1