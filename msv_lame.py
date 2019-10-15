t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')))
    max_count = 0
    for i in range(1, len(a)):
        this_count = 0
        for j in range(i):
            if(a[j]%a[i] == 0):
                this_count += 1
        if(this_count > max_count):
            max_count = this_count

    print(max_count)