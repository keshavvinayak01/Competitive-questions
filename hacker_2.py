
def get_chocolates(a, current, p, dp):
    if(current >= len(a)):
        return 10**9 + 1
    if(dp[current] >= 0):
        return dp[current]
    option1 = a[current]*p + get_chocolates(a, current+1, p, dp)
    option2 = (a[current] - a[current + 1])*p + get_chocolates(a, current+1, p, dp) if current != n-1 else float('inf')
    print(option1, option2)
    dp[current] = min(option1, option2)
    return dp[current]

t = int(input())
for _ in range(t):
    n, p = list(map(int, input().split()))
    a = list(map(int, input().split()))
    dp = [-1]*n
    print(get_chocolates(a, 0, p, dp))
    # print(cost)