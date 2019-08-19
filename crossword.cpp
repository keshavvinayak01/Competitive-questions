#include<bits/stdc++.h>
using namespace std;
#define N 10

bool checkHorizontal(int grid[N][N], string words[], int index, int row, int column){
	int count = 0;
	if(N - column < words[index].size()){
		return false;
	}
	for(int i = column; i < column + words[index].size(); i++){
		if(grid[row][i] == '-' || grid[row][i] == words[index][count]){
			count++;
		}
		else{
			break;
		}
	}
	if(count == words[index].size()){
		return true;
	}
	return false;
}

bool checkVertical(int grid[N][N], string words[], int index, int row, int column){
	int count = 0;
	for(int j = row; j < row + words[index].size(); j++){
		if(grid[j][column] == '-' || grid[j][column] == words[index][count]){
			count++;
		}
		else{
			break;
		}
	}
	if(count == words[index].size()){
		return true;
	}
	return false;	
}

void removeHorizontal(int grid[N][N], int row, vector<int> indices){
	for(int i=indices.begin(); i < indices.end(); i++){
		grid[row][indices[i]] = '-';
	}
}

void removeVertical(int grid[N][N], int column, vector<int> indices){
	for(int i=indices.begin(); i < indices.end(); i++){
		grid[row][indices[i]] = '-';
	}
}

void applyHorizontal(char grid[N][N], string words[], int index, int row, int column, vector<int> arr){
	int count = 0;
	for(int i = column; i < column + words[index].size(); i++){
		if(grid[row][i] == '-'){
			arr.push_back(i);			
			grid[row][i] = words[index][count++];
		}
		else if(grid[row][i] == words[index][count]){
			grid[row][i] = words[index][count++];
		}
	}
}

void applyVertical(char grid[N][N], string words[], int index, int row, int column, vector<int> arr){
	int count = 0;
	for(int i = row; i < row + words[index].size(); i++){
		if(grid[i][column] == '-'){
			arr.push_back(i);			
			grid[i][column] = words[index][count++];
		}
		else if(grid[i][column] == words[index][count]){
			grid[i][column] = words[index][count++];
		}
	}
}

bool solve_crossword(char grid[N][N], string words[], int index){
	if(index = words.size()){
		for(int i=0; i < N; i++){
			for(int j=0; j < N ; j++)
				cout<<grid[i][j];
			cout<<endl;
		}
		return true;
	}
	for(int i=0; i < N; i++){
		for(int j=0; j < N ; j++){
			if(grid[i][j] == '-' || grid[i][j] == words[index][0]){
				if(checkHorizontal(grid, words, index, i, j)){
					vector<int> arr;
					applyHorizontal(grid, words[index], i, j, arr);
					if(solve_crossword(grid, words, index+1)){
						return true;
					}
					removeHorizontal(grid, i, arr);
				}
				if(checkVertical(grid, words, index, j)){
					int arr[N];
					applyVertical(grid, words[index], j, arr);
					if(solve_crossword(grid, words, index+1)){
						return true;
					}
					removeVertical(grid, j, arr);
				}
			}
		}
	}
	return false;
}


int main(){

	char grid[N][N];
	for(int i=0; i < N;i++){
		string s;
		cin>>s;
		for(int j=0; j < N; j++){
			grid[i][j] = s[j];
		}
	}
	string k;
	cin>>k;
	string words[100];
	int start = 0;
	int word_count = 0;
	for(int i=0;i < k.size(); i++){
		while(k[i] != ';' && i < k.size()){
			words[word_count] += k[i];
			i++;
		}
		word_count++;
	}
	solve_crossword(grid, words, 0);
	return 0;
}