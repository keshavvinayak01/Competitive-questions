#include <bits/stdc++.h>
#define MAXN 2010
using namespace std;
int t, n, m, k, cnt[MAXN][MAXN];
vector<int> adj[MAXN];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool ans = false;
    int x, y;
    for (int i = 1; i <= n; i++) {
        if (ans)
            break;
        for (auto x: adj[i]) {
            if (ans)
                break;
            for (auto y: adj[i]) {
                if (x < y) {
                    cnt[x][y]++;
                    cnt[y][x]++;
                    if (cnt[x][y] >= k) {
                        ans = true;
                        break;
                    }
                }
            }
        }
    }
    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}