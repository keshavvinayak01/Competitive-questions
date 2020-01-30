#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

void get_edges(int row, int col, int** board, vector<int>* edges, int n, int m){
    // Check for the 8 positions and push to edge list
    // up right
    if(row - 2 >= 0 && col + 1 < m && board[row-2][col+1] >= 0) {
        edges[board[row][col]].push_back(board[row-2][col+1]);
    }
    // up left
    if(row - 2 >= 0 && col - 1 >= 0 && board[row-2][col-1] >= 0) {
        edges[board[row][col]].push_back(board[row-2][col-1]);
    }
    // down right
    if(row + 2 < n && col + 1 < m && board[row+2][col+1] >= 0) {
        edges[board[row][col]].push_back(board[row+2][col+1]);
    }
    // down left
    if(row + 2 < n && col - 1 >= 0 && board[row+2][col-1] >= 0) {
        edges[board[row][col]].push_back(board[row+2][col-1]);
    }
    // left up
    if(row - 1 >= 0 && col - 2 >= 0 && board[row-1][col-2] >= 0) {
        edges[board[row][col]].push_back(board[row-1][col-2]);
    }
    // right up
    if(row - 1 >= 0 && col + 2 < m && board[row-1][col+2] >= 0) {
        edges[board[row][col]].push_back(board[row-1][col+2]);
    }
    // left down
    if(row + 1 < n && col - 2 >= 0 && board[row+1][col-2] >= 0) {
        edges[board[row][col]].push_back(board[row+1][col-2]);
    }
    // right down
    if(row + 1 < n && col + 2 < m && board[row+1][col+2] >= 0) {
        edges[board[row][col]].push_back(board[row+1][col+2]);
    }
}

void dfs(vector<int>* edges, int start, int& component_size, bool* visited) {
    visited[start] = true;
    component_size++;
    for(int i = 0 ; i < edges[start].size(); i++) {
        int next = edges[start][i];
        if(!visited[next]) {
            dfs(edges, next, component_size, visited);   
        }
    }
}

int factorial(int n) {
    int ans = 1;
    for(int i = 1 ; i <= n; i++) ans = ((ans%MOD)*i)%MOD;
    return ans;
}

long long get_connected_sizes(vector<int>* edges, int n) {
    
    bool* visited = new bool[n];
    long long ans = 1;
    for(int i = 0 ; i < n ; i++) visited[i] = false;
    int component_size;
    for(int i = 0 ; i < n ; i++){
        if(!visited[i] && edges[i].size() <= 8 ) {
            component_size = 0;
            dfs(edges, i, component_size, visited);
            ans = ((ans%MOD)*factorial(component_size))%MOD;
        }
    }
    delete[] visited;
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--) {
        int n, m, q;
        cin >> n >> m >> q;

        int** board = new int*[n];
        for(int i = 0 ; i < n ; i++){
            board[i] = new int[m];
            for(int j = 0; j < m; j++){
                board[i][j] = -1;
            }
        }
        for(int i = 0 ; i < q ; i++) {
            int a, b;
            cin >> a >> b;
            board[a-1][b-1] = i;
        }
        vector<int>* edges = new vector<int>[n];
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m ; j++){
                if(board[i][j] > -1){
                    get_edges(i, j, board, edges, n, m);
                }
            }
        }
        cout << get_connected_sizes(edges, q) << endl;
        delete[] edges;
        for(int i = 0 ; i < n ; i++) delete[] board[i];
        delete[] board;
    }

    return 0;
}