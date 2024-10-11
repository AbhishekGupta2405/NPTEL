def isPowerOfTwo(x):
  return (x and (not(x & (x - 1))))
t = int(input())
if (t == 1):
  print("YES")
else:
  if (isPowerOfTwo(t)):
    print("YES")
  else:
    print("NO")