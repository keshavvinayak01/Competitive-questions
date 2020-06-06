#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, a, b, n, m, ans, cs, j;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        pair<int, int> arr[n];
        vector<pair<int, int>> free(m);
        for(int i = 0 ; i < n ; i++) cin >> arr[i].first;
        for(int i = 0 ; i < m ; i++) {
            cin >> a >> b;
            free.push_back(make_pair(a, b));
        }
        for(int i = 0 ; i < n ; i++) {arr[i].second = i;}
        sort(arr, arr + n);
        bool vis[n];
        memset(vis, false, sizeof(vis));
        ans = 0;
        for(int i = 0 ; i < n ; i++) {
            if(vis[i] || arr[i].second == i) continue;
            cs = 0; j = i;
            while(!vis[j]) {
                vis[j] = true;
                j = arr[j].second;
                cs++;
            }
            ans = cs > 0 ? ans + cs - 1 : ans;
        }
        cout << ans << endl;
    }
    return 0;
}