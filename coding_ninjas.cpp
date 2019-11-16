#include<bits/stdc++.h>
using namespace std;

void containString(int** edges, int n, int k, string main) {
    n = n*k;
    bool* visited = new bool[n];
    queue<int> pendingVertices;
    int start = -1;
    pendingVertices.push(0);
    visited[0] = true;

    while(!pendingVertices.empty()) {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();  
        visited[sv] = true;
        cout << currentVertex << " ";
        for(int i = 0; i < n; i++) {
            if(i == currentVertex) continue;
            if(edges[currentVertex][i] == 1 && !visited[i]) {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    delete[] visited;
}
                                                                        
int main() {                                                                                    
    int n, k;                                                                                   
    cin >> n >> k;                                                                              
    int** edges = new int*[n*k];
    for(int i = 0 ; i < n*k; i++) edges[i] = new int[n*k];
    string fullString = "";
    string* graph = new string[n];

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        graph[i] = s;
        fullString += s;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k ; j++) {
            edges[k*i + j][j+1] = edges[j+1][k*i + j] = 1;                 // right
            edges[k*i + j][(k+1)*i + 1] = edges[(k+1)*i + 1][k*i + j] = 1; // bottom-right
            edges[k*i + j][(k + 1)*i] = edges[(k + 1)*i][k*i + j] = 1;     // bottom
            edges[k*i + j][(k+1)*i - 1] = edges[(k+1)*i - 1][k*i + j] = 1; // bottom-left
            edges[k*i + j][j-1] = edges[j-1][k*i + j] = 1;                 // left
            edges[k*i + j][(k-1)*i - 1] = edges[(k-1)*i - 1][k*i + j] = 1; // left-top
            edges[k*i + j][(k-1)*i] = edges[(k-1)*i][k*i + j] = 1;         // top
            edges[k*i + j][(k-1)*i + 1] = edges[(k-1)*i + 1][k*i + j] = 1; // right-top
        }
    }
    string main = "CODINGNINJA";
    
    cout << containString(edges, n, k, main) << endl;
    return 0;
}