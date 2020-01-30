## Read input as specified in the question.
## Print output as specified in the question.

def keypad(num, output, keypad_map):
    if(num%10 == num):
        for i in range(len(keypad_map[num])):
            output[i] = keypad_map[num][i]
        return len(keypad_map[num])

    smallNumber = num%10
    smallOutputSize = keypad(num//10, output, keypad_map)
    for j in range(len(keypad_map[smallNumber])):
        for i in range(smallOutputSize):
            output[i + (j+1)*smallOutputSize] = output[i] + keypad_map[smallNumber][j]

    return (len(keypad_map[smallNumber]) + 1)*smallOutputSize

a = int(input())
keypad_map = {
    2 : ['a','b','c'],
    3 : ['d','e','f'],
    4 : ['g','h','i'],
    5 : ['j', 'k', 'l'],
    6 : ['m', 'n', 'o'],
    7 : ['p', 'q', 'r', 's'],
    8 : ['t', 'u', 'v'],
    9 : ['w', 'x', 'y', 'z']
}
output = ['']*10000

length = len(str(a))

size = keypad(a, output, keypad_map)
for i in range(size):
    if(len(output[i]) == length):
        print(output[i])    
