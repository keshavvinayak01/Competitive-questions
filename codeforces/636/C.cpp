#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli t, n;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        lli arr[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        lli i = 0, max_curr;
        lli ans = 0;
        while(i < n) {
            max_curr = LLONG_MIN;
            while(arr[i] > 0 && i < n) {
                max_curr = max(max_curr, arr[i]);
                i++;
            }
            if(max_curr != LLONG_MIN) ans += max_curr;
            max_curr = LLONG_MIN;
            while(arr[i] < 0 && i < n) {
                max_curr = max(max_curr, arr[i]);
                i++;
            }
            if(max_curr != LLONG_MIN) ans += max_curr;
        }
        cout << ans << endl;
    }

    return 0;
}