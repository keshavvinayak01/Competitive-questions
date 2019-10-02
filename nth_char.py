def get_ans():
    input1 = input()
    current_max = 0
    max_ans = 0
    opening = ["(", "[", "{"]
    closing = [")", "]", "}"]
    fin_string = ""
    for i in input1:
        if(i in closing + opening):
            fin_string += i
    n = len(fin_string)
    for i in range(n):
        if fin_string[i] in opening:
            current_max += 1
            if current_max > max_ans:
                max_ans = current_max
        elif fin_string[i] in closing:
            if current_max > 0:
                current_max = -1
            else:
                break
    return max_ans

print(get_ans())