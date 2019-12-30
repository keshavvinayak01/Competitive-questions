#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void DFS(vector<int>* edges, int start, ll* values, bool* visited, ll &component_value) {
    visited[start] = true;
    component_value += values[start];
    for(int i = 0; i < edges[start].size(); i++) {
        int next = edges[start][i];
        if(!visited[next]) {
            DFS(edges, next, values, visited, component_value);
        }
    }
}

void maxPrize(vector<int>* edges, ll* values, int n) {
    bool* visited = new bool[n];
    ll maxValue = -1;
    for(int i = 0 ; i < n; i++) {
        if(!visited[i]) {
            ll componentValue = 0;
            DFS(edges, i, values, visited, componentValue);
            maxValue = max(componentValue, maxValue);
        }
    }
    cout << maxValue << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int>* edges = new vector<int>[n];
        for(int i = 0 ; i < m ; i++) {
            int a, b;
            cin >> a >> b;
            edges[a-1].push_back(b-1);
            edges[b-1].push_back(a-1);
        }
        ll* values = new ll[n];
        for(int i = 0 ; i < n ; i++) cin >> values[i];
        maxPrize(edges, values, n);
    }

    return 0;
}