#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli t, x, y, l, r;
    cin >> t;
    while(t--) {
        cin >> x >> y >> l >> r;
        lli maxi = max(x, y);
        if(x == 0 || y == 0) {
            cout << 0 << endl;
            continue;
        }
        lli ans = pow(2, (int)log2(maxi) + 1) - 1;
        cout << ans << endl;        
    }

    return 0;
}