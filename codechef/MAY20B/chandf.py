from math import log2, ceil

def calc(a, b, c):
    return (a & c) * (b & c)

t = int(input())
while(t > 0):
    x, y, l, r = list(map(int, input().split()))
    if(x == 0 or y == 0 or (l == 0 and r == 0)):
        print(0)
        t -= 1
        continue
    xb = (bin(min(x, y)))[2:]
    yb = (bin(max(x, y)))[2:]
    xb = (len(yb) - len(xb))*"0" + xb
    ans = bin(x | y)[2:]
    ans3 = int('0b' + ans[-1*ceil(log2(r)):], 2) 
    ans1 = int('0b' + ''.join(ans), 2) & r
    ans2 = (pow(2, int(log2(r))) - 1) & int('0b' + ''.join(ans), 2)
    if(calc(x, y, ans3) == calc(x, y, ans2)):
        print(min(ans2, ans3))
    elif(calc(x, y, ans3) == calc(x, y, ans1)):
        print(min(ans2, ans3))
    elif(calc(x, y, ans2) == calc(x, y, ans1) and calc(x, y, ans1) == calc(x, y, ans3)):
        print(min(ans2, min(ans1, ans3)))
    if(ans3 <= r):
        print(ans3)
    elif(calc(x, y, ans1) > calc(x, y, ans2)):
        print(ans1)
    else:
        print(ans2)
    t -= 1