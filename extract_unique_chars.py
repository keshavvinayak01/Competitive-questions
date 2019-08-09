def uniqueChars(string):
	result = {}
	for i in string:
		try : 
			result[i] += 1
		except:
			result[i] = 1
	result_string = ''
	for i in string:
		if result[i] >= 1:
			result_string += i
			# result[i] = 0
	return result_string

string = input()
print(uniqueChars(string))