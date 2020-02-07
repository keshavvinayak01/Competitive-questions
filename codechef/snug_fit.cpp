#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli t, n, ans;
    cin >> t;
    while(t--) {
        cin >> n;
        lli arr1[n], arr2[n];
        for(int i = 0 ; i < n ; i++) cin >> arr1[i];
        for(int i = 0 ; i < n ; i++) cin >> arr2[i];
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + n);
        ans = 0;
        for(int i = 0 ; i < n ; i++) {
            ans += min(arr1[i], arr2[i]);
        }
        cout << ans << endl;
    }

    return 0;
}