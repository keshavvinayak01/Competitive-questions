#include<bits/stdc++.h>
using namespace std;

void removeConsecutiveDuplicates(char *input) {
	if(input[0] == '\0')
		return;
	if(input[0] == input[1]){
		int i= 1;
		for(;input[i] != '\0'; i++)
			input[i-1] = input[i];
		input[i-1] = input[i];
		removeConsecutiveDuplicates(input);
	}
	removeConsecutiveDuplicates(input + 1);
}

int main(){

	string s;
	cin>>s;
	int n = s.length();
	char char_array[n - 1];
	strcpy(char_array, s.c_str()); 
	removeConsecutiveDuplicates(char_array);
	cout<<char_array;
	return 0;
}