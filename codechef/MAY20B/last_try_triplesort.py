t = int(input())
while(t > 0):
    n, k = list(map(int, input().split(' ')))
    arr = list(map(int, input().split(' ')))
    temp = sorted(arr)
    indices = {}
    for i, val in enumerate(temp):
        indices[val] = i
    op = i = 0
    val_f = -1
    val_s = -1
    operations = []
    ans = True
    while(i < n):
        if(arr[i] == temp[i] or val_s == i):
            i += 1
            continue
        e1 = i
        e2 = indices[arr[e1]]
        e3 = indices[arr[e2]]
        if(e1 == e3 and val_f == -1):
            val_f = e1
            val_s = e2
            i += 1
            continue
        if(e3 == e1):
            e1 = val_f
            e2 = val_s
            e3 = i
            val_f = -1
            val_s = -1
        temp2 = arr[e3]
        arr[e3] = arr[e2]
        arr[e2] = arr[e1]
        arr[e1] = temp2
        op += 1
        operations.append([e1 + 1, e2 + 1, e3 + 1])
        if(arr[e1] == temp[e1]):
            i += 1
        if(op > k):
            ans = False
            break
    if(val_f != -1):
        ans = False
    if(op <= k and ans):
        print(op)
        for el in operations:
            a = min(el[0], min(el[1], el[2]))
            c = max(el[0], max(el[1], el[2]))
            b = sum(el) - a - c
            print(a, b, c)
    else:
        print(-1)
    t -= 1