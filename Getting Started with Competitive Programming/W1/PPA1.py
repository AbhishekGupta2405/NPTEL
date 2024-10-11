"""
You begin with a stack of n boxes.

Then you make a sequence of moves. In each move, you divide one stack of boxes into two nonempty stacks. The game ends when you have n stacks, each containing a single box. You earn points for each move; in particular, if you divide one stack of height a + b into two stacks with heights a and b, then you score ab points for that move. Your overall score is the sum of the points that you earn for each move.

What strategy should you use to maximize your Total score ?

nput Format

The first line is T, the number of test cases.
The next T lines have one test case each.
Each test case is a number 1 <= N <= 10000, which is the size of the first stack of boxes.

Output Format

For each test case, output the best possible score that you can earn with an optimal strategy.
Your output should have N lines, with the i-th line containing the answer for the i-th test case.
"""
t = int(input())
while(t):
  lis =[]
  n = int(input())
  if (n>1):
    lis.append(n)
  else:
    print(0)
  ans = 0
  while (len(lis)):
    n = lis.pop(0)
    n1 = n//2
    n2 = n - n1
    if (n1 > 1):
      lis.append(n1)
    if (n2 > 1):
      lis.append(n2)
    ans += (n1*n2)
  print(ans)
  t-=1