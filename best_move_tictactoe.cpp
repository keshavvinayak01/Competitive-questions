#include<bits/stdc++.h>
using namespace std;

char** makeAMove(char** board, int x, int y, char player);
void printBoard(char** board);
bool hasWon(char** board) {
    for(int i = 0 ; i < 3 ; i++) {
        // Check horizontal victory
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == 'x')
            return true;

        // Check vertical victory
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == 'x')
            return true;
    }
    // Check diagonal victory
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 'x')
        return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == 'x')
        return true;
    
    return false;
}

vector<pair<int, int>*>* possibleMoves(char** board, char player) {
	vector<pair<int, int>*>* output = new vector<pair<int, int>*>();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] != 'o' && board[i][j] != 'x') {
                pair<int, int>* p = new pair<int, int>(i, j);
                output->push_back(p);
			}
        }
    }	
	return output;
}

int evaluateBoard(char** board, bool& completed) {
	if (possibleMoves(board, 'o')->size() != 0 || possibleMoves(board, 'x')->size() != 0) {
		completed = false;
		return 0;
	}
	// cout << "here" << endl;
	completed = true;
    // Count the total number of moves made by x

    int totalMoves = 0;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++) {
            if(board[i][j] == 'x') {
                totalMoves++;
            }
        }
    }
    if(hasWon(board)) {
        // cout << "Total moves : " << totalMoves << endl;
        return 10 - totalMoves;
    }
    else return totalMoves - 10;
}

char** makeAMove(char** board, int x, int y, char player) {

	char** newBoard;
	newBoard = new char*[3];
    for (int i = 0; i < 3; i++) {
        newBoard[i] = new char[3];
        for (int j = 0; j < 3; j++) {
            newBoard[i][j] = board[i][j];
        }
    }

	if(x < 0 || x >= 3 || y < 0 || y >= 3 || board[x][y] == 'x' || board[x][y] == 'o'){
		return NULL;
	}

    newBoard[x][y] = player;
    // cout << "**************\n";
    // printBoard(newBoard);
    // cout << "**************\n";
	return newBoard;
}

void printBoard(char** board) {
	for (int i = 0 ; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int findNextStep(char** board, bool maximizerTurn, int& x, int& y) {
	// check if done with play if yes return score of evaluate function
	bool completed;
	int score = evaluateBoard(board, completed);
	if (completed) {
        // cout << score << endl;
        // cout << "Completed!\n";
		return score;
	}

	// find all possible moves
	char player = maximizerTurn? 'x' : 'o';
	vector<pair<int, int>*>* options = possibleMoves(board, player);
	if (options->size() == 0) {
		x = -1;
		y = -1;
		int dummyX, dummyY;
		return findNextStep(board, !maximizerTurn, dummyX, dummyY);
	}
	int best;
	if (maximizerTurn) {
		best = INT_MIN;
	} else {
		best = INT_MAX;
	}
	// for each move 
	for (int i = 0; i < options->size(); i++) {
		// 	Make the move
		int currentMoveX = options->at(i)->first;	
		int currentMoveY = options->at(i)->second;	
		char** newBoard = makeAMove(board, currentMoveX, currentMoveY, player);
		//	Make recursive call
		int dummyX, dummyY;
		
		int score = findNextStep(newBoard, !maximizerTurn, dummyX, dummyY);
		//  update best (will be min/max depending on who's turn it is)
		if (maximizerTurn) {
			best = max(best, score);
		} else {
			best = min(best, score);
		}
		if (best == score) {
			x = currentMoveX;
			y = currentMoveY;
		}
		//	Undo the move. We will have to maintain a copy of the board for this.
		for (int i = 0; i < 3; i++) {
			delete [] newBoard[i];
		}
		delete [] newBoard;
	}
	// update x & y and return best score
	return best;
}

int main() {
    int n;
    cin >> n;
    char** board = new char*[3];
    for(int i = 0 ; i < 3; i++) {
        board[i] = new char[3];
        for(int j = 0 ; j < 3; j++) board[i][j] = ' ';
    }
    for(int i = 0 ; i < n ; i++) {
        int a, b;
        char move;
        cin >> a >> b >> move;
        board[a][b] = move;
    }
    int x, y;
    cout << findNextStep(board, true, x, y) << " ";
    cout << "row: " << x << " " << "col: " <<  y << endl;
    return 0;
}