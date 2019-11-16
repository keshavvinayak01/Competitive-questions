#include<bits/stdc++.h>
using namespace std;

void DFS(bool** graph, int n, int start, bool* visited) {
    visited[start] = true;
    for(int i = 0; i < n; i++) {
        if(i == start) continue;
        if(graph[start][i]) {
            if(visited[i]) continue;
            DFS(graph, n, i, visited);
        }
    }
}


int countConnected(bool** graph, int n) {
    int connected = 0;
    bool* visited = new bool[n];
    for(int i = 0 ; i < n; i++) {
        if(!visited[i]){
            DFS(graph, n, i, visited);
            connected += 1;
        } 
    }
    return connected;
}
int solve(int n, int m, vector<int> u, vector<int> v) {
    bool** graph = new bool*[n];
    for(int i = 0; i < n; i++) {
        graph[i] = new bool[n];
        for(int j = 0; j < n; j++) 
            graph[i][j] = false;
    }
    for(int i = 0 ; i < m; i++) {
        graph[u[i] - 1][v[i] - 1] = true;
        graph[v[i] - 1][u[i] - 1] = true;
    }
    return countConnected(graph, n);
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> start;
    vector<int> end;
    for(int i = 0 ; i < m; i++) {
        int x;
        cin >> x;
        start.push_back(x);
    }
    for(int i = 0 ; i < m; i++) {
        int x;
        cin >> x;
        end.push_back(x);
    }

    cout << solve(n, m, start, end) << endl;
    return 0;
}