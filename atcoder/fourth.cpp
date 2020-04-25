#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli n, k;
    cin >> n >> k;
    if(k == n + 1) cout << 1 << endl;
    else {
        lli arr1[n+1], arr2[n+1];
        arr1[0] = 0;
        arr2[n] = n + 1;
        for(int i = 1 ; i <= n; i++) {
            arr1[i] = (arr1[i-1] + i) % MOD;
        }
        for(int i = n; i >= 1; i--) {
            arr2[i-1] = (arr2[i] + i) % MOD;
        }
        lli res = 0;
        for(int i = 1 ; i <= n-k ; i++) {
            res += arr2[n-i] - arr1[i];
        }
        cout << res << endl;
    }
    
    return 0;
}