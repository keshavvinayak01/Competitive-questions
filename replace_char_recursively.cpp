#include<bits/stdc++.h>
using namespace std;

void replaceCharacter(char input[], char c1, char c2){
	if(input[0] == '\0')
		return;
	if(input[0] == c1){
		input[0] = c2;
	}
	replaceCharacter(input + 1, c1, c2);	
}

int main(){

	string s;
	cin>>s;
	char c1, c2;
	int n = s.length();
	char char_array[n - 1];
	cin>>c1>>c2;
	strcpy(char_array, s.c_str()); 
	replaceCharacter(char_array, c1, c2);
	cout<<char_array;

	return 0;
}