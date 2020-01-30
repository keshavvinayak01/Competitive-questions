#include<bits/stdc++.h>
using namespace std;

bool connectedDots(char** graph, int row, int col, int nrow, int ncol, char a, int srow, int scol, int loopSize) {
    if(row < 0 || col < 0 || row >= nrow || col >= ncol) {
        return false;
    }
    if(row == srow && col == scol && loopSize >= 4) {
        return true;
    }
    if(graph[row][col] == a) {
        graph[row][col] = '#';
        bool res = connectedDots(graph, row-1, col, nrow, ncol, a, srow, scol, loopSize+1) |
                   connectedDots(graph, row+1, col, nrow, ncol, a, srow, scol, loopSize+1) |
                   connectedDots(graph, row, col-1, nrow, ncol, a, srow, scol, loopSize+1) |
                   connectedDots(graph, row, col+1, nrow, ncol, a, srow, scol, loopSize+1) ;
        graph[row][col] = a;
        return res;
    }
    else return false;
}

int solve(char** graph, int n, int m) {
    string all = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 0; i < all.size(); i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0 ; k < m; k++) {
                if(graph[j][k] == all[i]) {
                    if(connectedDots(graph, j, k, n, m, graph[j][k], j, k, 0)){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    char** graph = new char*[n];
    for(int i = 0; i < n; i++){
        graph[i] = new char[m];
        string s;
        cin >> s;
        for(int j = 0 ; j < m ; j++) {
            graph[i][j] = s[j];
        }
    }
    cout << solve(graph, n, m) << endl;

    return 0;
}