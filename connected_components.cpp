#include<bits/stdc++.h>
using namespace std;

void DFS(bool** graph, int n, int start, bool* visited, vector<int> &component) {
    visited[start] = true;
    component.push_back(start);
    for(int i = 0; i < n; i++) {
        if(i == start) continue;
        if(graph[start][i]) {
            if(visited[i]) continue;
            DFS(graph, n, i, visited, component);
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    bool** graph = new bool*[n];
    for(int i = 0; i < n ; i++) graph[i] = new bool[n];

    for(int i = 0 ; i < e; i++) {
        int s, e;
        cin >> s >> e;
        graph[s][e] = true;
        graph[e][s] = true;
    }
    bool* visited = new bool[n];
    for(int i = 0 ; i < n; i++) {
        if(!visited[i]) {
            vector<int> component;
            DFS(graph, n, i, visited, component);
            vector<int>::iterator it;
            sort(component.begin(), component.end());
            for(it = component.begin(); it < component.end(); it++) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }

    return 0;
}