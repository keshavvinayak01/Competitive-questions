#include<bits/stdc++.h>
using namespace std;

void getBFS(int** edges, int n, int start, int end, int* graph) {
    bool* visited = new bool[n];
    for(int i = 0 ; i < n ; i++) visited[i] = false;
    queue<int> pendingVertices;
    pendingVertices.push(start);
    visited[start] = true;
    while(!pendingVertices.empty()) {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();  
        visited[currentVertex] = true;
        for(int i = 0; i < n; i++) {
            if(i == currentVertex) continue;
            if(edges[currentVertex][i] == 1 && !visited[i]) {
                pendingVertices.push(i);
                graph[i] = currentVertex;
                visited[i] = true;
                if(i == end) {
                    delete[] visited;
                    return;
                }
            }
        }
    }
    delete[] visited;
    return;
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
    int* graph = new int[n];
    for(int i = 0 ; i < n; i++) graph[i] = -1;  
    getBFS(edges, n, start, end, graph);
    if(graph[end] == -1) return 0;
    int i = end;
    cout << end << " ";
    while(i != start) {
        cout << graph[i] << " ";
        i = graph[i];
    }    
    return 0;
}