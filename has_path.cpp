#include<bits/stdc++.h>
using namespace std;

bool hasPathBFS(int** edges, int n, int start, int end) {
    queue<int> pendingVertices;
    bool* visited = new bool[n];

    for(int i = 0; i < n; i++) visited[i] = false;
    visited[start] = true;
    pendingVertices.push(start);

    while(!pendingVertices.empty()) {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();  
        visited[currentVertex] = true;
        for(int i = 0; i < n; i++) {
            if(i == currentVertex) continue;
            
            if(edges[currentVertex][i] == 1 && !visited[i]) {
                if(i == end) {
                    delete[] visited;
                    return true;
                }
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    delete[] visited;
    return false;
}

int main() { 
    int n, e;
    cin >> n >> e;
    int** edges = new int*[n];
    for(int i = 0; i < n; i++) {
        edges[i] = new int [n];
        for(int j = 0; j < n; j++) edges[i][j] = 0;
    }
    for(int i = 0 ; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int start, end;
    cin >> start >> end;
    if(hasPathBFS(edges, n, start, end)) {
        cout << "true\n";
    }
    else {
        cout << "false\n";
    }
    return 0;
}