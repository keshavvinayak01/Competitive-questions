from numpy.random import choice

options = [i for i in range(1, 10)]

t = int(input())
for _ in range(t):
    n, m, k = list(map(int, input().split(' ')))
    answers = [[0]*k]*n
    for i in range(n):
        answers[i] = list(map(int, input().split(' ')))
    wrong_list = {i : False for i in range(k)}
    wrong = 0
    for i in range(n):
        if(wrong == n): 
            wrong_list = {i : False for i in range(k)}
            wrong = 0
        prob_count = {i : 0 for i in range(1, 10)}
        temp_k = 0
        for j, item in enumerate(answers[i]):
            if wrong_list[j]:
                prob_count[item] += 0.28
                temp_k += 0.28
            else :
                prob_count[item] += 1.1
                temp_k += 1.1
        prob_dist = [prob_count[x]/temp_k for x in prob_count.keys()]
        draw = choice(options, 1, p = prob_dist)
        print(draw[0], end = ' ')
        for j, item in enumerate(answers[i]):
            if(item != draw[0]):
                wrong_list[j] = True
                wrong += 1
    print()