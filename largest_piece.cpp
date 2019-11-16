#include<bits/stdc++.h>
using namespace std;

int largestPiece(char** graph, int n, int row, int col) {
    if(row < 0 || col < 0 || row >= n || col >= n) {
        return 0;
    }
    // cout << row << " " << col << endl;
    if(graph[row][col] == '1') {
        graph[row][col] = '#';
        int option1 = 1 + largestPiece(graph, n, row-1, col);
        int option2 = 1 + largestPiece(graph, n, row+1, col);
        int option3 = 1 + largestPiece(graph, n, row, col-1);
        int option4 = 1 + largestPiece(graph, n, row, col+1);  
        int max1 = max(option1, option2);
        int max2 = max(option3, option4);
        graph[row][col] = '1';
        return max(max1, max2);
    }
    else return 0;
}

int solve(int n, char** graph) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(graph[i][j] == '1') {
                return largestPiece(graph, n, i, j);
            }
        }
    }
    return 0;
}

int main() {
    int n;
    cin >> n ;
    char** graph = new char*[n];
    for(int i = 0; i < n; i++){
        graph[i] = new char[n];
        for(int j = 0 ; j < n ; j++) {
            cin >> graph[i][j];
        }
    }
    cout << solve(n, graph) << endl;

    return 0;
}