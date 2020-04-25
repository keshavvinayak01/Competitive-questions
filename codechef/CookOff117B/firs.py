for _ in range(int(input())):
  n , q = map(int , input().split())
  arr = []
  curr = ans = 0
  for i in range(q):
    first, second = map(int , input().split())
    ans += abs(curr - first)
    curr = first
    ans += abs(first-second)
    curr = second
  print(ans)