# for ii in range(int(input())):
#   t = input()
#   n = len(t)
#   temp = 10000
#   f = 1
#   for i in range(1, 101):
#     f = 1
#     for j in range(n-i):
#       if t[j] != t[j+i]:
#         f = 0
#         break
#     if f: temp = min(temp, i); break
#   #print(temp)
#   if temp == 1 or temp == 2: print(t); continue
#   ans = ""
#   if t[0] == "1":
#     ans+="1"
#   else:
#     ans+="0"
#   for i in range(1,2*n):
#     if ans[i-1] == "0":
#       ans+="1"
#     else:
#       ans+="0"
#   print(ans)

t = int(input())
while t > 0:
    s = input()
    temp = 10000
    for i in range(1, 101):
        f = True
        for j in range(len(s)-i) :
            if(s[j] != s[j + i]):
                f = False
                break
        if f:
            temp = min(i, temp)
            break
    if(temp == 2 or temp == 1): 
        print(s)
        t -= 1
        continue
    fin_ans = ""
    fin_ans += s[0]
    for i in range(1, 2*len(s)):
        if(fin_ans[i-1] == "0"):
            fin_ans += "1"
        else:
            fin_ans += "0"
    print(fin_ans)
    t -= 1