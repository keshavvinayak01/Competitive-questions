#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, q, a, b;
        cin >> n >> q;
        int ans = 0, curr = 0;
        pair<int, int> queries[q];
        for(int i = 0 ; i < q ; i++) {
            cin >> a >> b;
            queries[i] = {a, b};
        }
        for(int i = 0 ; i < q; i++) {
            ans += abs(curr - queries[i].first);
            curr = queries[i].first;
            ans += abs(queries[i].first - queries[i].second);
            curr = queries[i].second;
        }
        cout << ans << endl;
    }

    return 0;
}