#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, ans, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        int fruits[n], costs[n], total_costs[m+1], exists[m+1];
        for(int i = 0 ; i <= m ; i++) {
            total_costs[i] = 0;
            exists[i] = 0;
        }

        for(int i = 0 ; i < n ; i++) {
            cin >> fruits[i];
            exists[fruits[i]] += 1;
        }

        for(int i = 0 ; i < n ; i++) cin >> costs[i];
        
        for(int i = 0 ; i < n; i++) total_costs[fruits[i]] += costs[i];
        
        ans = INT_MAX;
        for(int i = 1 ; i <= m ; i++) {
            if(exists[i] > 0)
                ans = min(total_costs[i], ans);
        }
        ans = ans == -INT_MAX ? 0 : ans;
        cout << ans << endl;
    }
    return 0;
}