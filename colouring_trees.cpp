#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void exploreDFS(bool** edges, ll n, ll current, bool* visited, ll* count) {

    visited[current] = true;
    count[current]++;
    for(ll i = 0; i < n; i++) {
        if(i == current) continue;
        if(edges[current][i]) {
            if(!visited[i]) {
                exploreDFS(edges, n, i, visited, count);
            }
            else count[i]++;
        }
    }
}

int main() {
    ll n, k;
    cin >> n >> k;
    bool** edges = new bool*[n];
    for(ll i = 0; i < n; i++) edges[i] = new bool[n];
    for(ll i = 0; i < n-1; i++) {
        ll a, b;
        cin >> a >> b;
        a--;b--;
        edges[a][b] = 1;
        edges[b][a] = 1; 
    }
    ll* terminals = new ll[k];
    for(ll i = 0; i < k; i++) {
        cin >> terminals[i]; 
    }
    bool* visited = new bool[n];
    ll* count = new ll[n];
    
    for(ll i = 0 ; i < n; i++) visited[i] = false;
    for(ll i = 0; i < n; i++) count[i] = 0;

    exploreDFS(edges, n, 0, visited, count);
    ll currTerm = 0;
    ll crowded = k;
    for(ll i = 0; i < n; i++) {
        if(i == terminals[i]-1){
            currTerm++;
        }
        else {
            if(count[i] > 1) crowded++;
        }
    }
    cout << crowded << endl;
}