def get_single_ans(ls):
    if(len(ls) == 0 or ls[0] > 1): return 1
    else:
        for i in range(1, len(ls)):
            if(ls[i] - ls[i-1] > 1): return ls[i] - 1
    return ls[-1] + 1
def sub_lists(list1): 
    sublist = [[]] 
    for i in range(len(list1) + 1): 
        for j in range(i + 1, len(list1) + 1): 
            sub = list1[i:j] 
            sublist.append(sub) 
    ans = 0
    print(sublist)
    for arr in sublist:
        ans += get_single_ans(arr)
    return ans
  
t = int(input())
while(t > 0):
    n = int(input())
    arr = list(map(int, input().split(' ')))
    arr = sorted(arr)
    t -= 1
    print(sub_lists(arr))