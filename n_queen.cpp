// BACKTRACKING

// 1. Place yourself at start point
// 2. Explore all the paths possible from that starting point
// 3. Insert your element at only correct possible position and once inserted,
// 	move onto smaller problem.
// 4. Once your reach base case, print your solution. 
// 5. Once you explore all paths from one point, backtrack to your previous point.


#include<bits/stdc++.h>
using namespace std;
int board[11][11];

bool isPossible(int n, int row, int column){
	
	// Same column
	for(int i= row-1; i>=0;i--){
		if(board[i][column] == 1)
			return false;
	}
	
	//  Upper left diagonal
	for(int i = row-1,j = column-1; i>=0 && j>=0; i--, j--){
		if(board[i][j] == 1)
			return false;
	}		

	// Upper right diagonal
	for(int i= row-1, j = column + 1; i>=0 && j < n; i--,j++){
		if(board[i][j] == 1)
			return false;
	}
	return true;
}

void nQueenHelper(int n, int row){
	if(row == n){
		// We have reached some solution
		// Print the board matrix
		// return
		cout<<"Possible Solution : "<<endl;
		for(int i = 0 ; i < n;i++){
			for(int j=0;j<n;j++){
				cout<<board[i][j]<<" ";
			}
		}
		cout<<endl;
		return;
	}
	// Place at all possible position and move to smaller problem
	for(int j=0; j < n; j++){
		if(isPossible(n,row,j)){
			board[row][j] = 1;
			nQueenHelper(n, row+1);
			board[row][j] = 0;
		}
	}
	return;
}


void placeNQueens(int n){	
	memset(board,0,11*11*sizeof(int));
	nQueenHelper(n, 0);
}



int main(){

	placeNQueens(4);

	return 0;
}