#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        ll arr[n][m];
        for(ll i = 0 ; i < n ; i++)
            for(ll j = 0 ; j < m ; j++)
                cin >> arr[i][j];
        ll ans = n*m;

        for(ll i = 0 ; i < n; i++) {
            for(ll j = 0; j < m; j++) {
                ll rh = j+1, lh = j-1;
                ll rv = i+1, lv = i-1;
                while((rh < m && lh >= 0) && (rv < n  && lh >= 0) && 
                    (arr[i][rh] == arr[i][lh] && arr[rv][j] == arr[lv][j])
                ){
                    // cout << "Didn't run?\n";
                    ans++;
                    rh++;lh--;
                    rv++;lv--;
                }
            }
        }
        cout << ans << endl;
        
    }

    return 0;
}