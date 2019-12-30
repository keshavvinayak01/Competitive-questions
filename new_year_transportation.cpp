#include<bits/stdc++.h>
using namespace std;

bool hasPath(vector<int>* edges, int start, int end, int n) {
    bool* visited = new bool[n];
    queue<int> pendingVertices;
    visited[start] = true;
    pendingVertices.push(start);
    while(!pendingVertices.empty()) {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        for(int i = 0 ; i < edges[currentVertex].size(); i++) {
            int nextVertex = edges[currentVertex][i];
            if(nextVertex == end) {
                delete[] visited;
                return true;
            }
            if(!visited[nextVertex]) {
                visited[nextVertex] = true;
                pendingVertices.push(nextVertex);
            }
        }
    }
    delete[] visited;
    return false;
}

int main() {
    int n, t;
    cin >> n >> t;
    vector<int>* edges = new vector<int>[n];
    for(int i = 0 ; i < n ; i++) {
        int a;
        cin >> a;
        edges[i].push_back(i + a);
    }
    if(hasPath(edges, 0, t-1, n)) {
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}