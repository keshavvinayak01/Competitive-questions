import numpy as np
t = int(input())
for _ in range(t):
    n, m, k = list(map(int, input().split(' ')))
    l = np.zeros(shape=(n,m))
    for _ in range(k):
        x, y = list(map(int, input().split()))
        l[x-1] += 1
        l[:, y-1] += 1
    print(len(l[l%2 != 0]))