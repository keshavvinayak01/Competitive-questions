#include<bits/stdc++.h>
#define MOD 1000000007
typedef long long int lli;
using namespace std;

int main() {
    int n, u, v;
    cin >> n;
    vector<vector<int>> edges(n);
    for(int i = 0 ; i < n-1; i++) {
        cin >> u >> v;
        edges[u-1].push_back(v-1);
        edges[v-1].push_back(u-1);
    }
    int values[n];
    return 0;
}