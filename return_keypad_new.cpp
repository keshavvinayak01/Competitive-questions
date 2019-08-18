#include<bits/stdc++.h>
using namespace std;

void possible_strings(int input, string output, map<int, vector<char>> keypad_map, int length){
	if(input == 0){
		if(output.size() == length)
			cout<< output << endl;
		return;
	}
	int smallNumber = input%10;
	possible_strings(input/10, output, keypad_map, length);
	for(int i=0; i < keypad_map[smallNumber].size(); i++)
		possible_strings(input/10, keypad_map[smallNumber][i] +  output, keypad_map, length);
}

int main(){

	map<int, vector<char>> keypad_map;
	keypad_map[2] = {'a','b','c'};
	keypad_map[3] = {'d','e','f'};
	keypad_map[4] = {'g','h','i'};
	keypad_map[5] = {'j','k','l'};
	keypad_map[6] = {'m','n','o'};
	keypad_map[7] = {'p','q','r','s'};
	keypad_map[8] = {'t','u','v'};
	keypad_map[9] = {'w','x','y','z'};

	int input;
	cin >> input;
	int length = 0;
	int temp = input;
	while(temp > 0){
		temp = temp /10;
		length++;
	}
	string output = "";
	possible_strings(input, output, keypad_map, length);
	
	return 0;
}