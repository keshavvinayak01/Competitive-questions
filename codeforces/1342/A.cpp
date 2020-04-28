#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli t,x, y, a, b, mn, mx;;
    cin >> t;
    while(t--) {
        cin >> x >> y;
        cin >> a >> b;
        mn = min(x, y);
        mx = max(x, y);
        lli option1 = abs(mn)*b + abs((mx - mn)*a);
        lli option2 = abs((abs(mx) + abs(mn))*a);
        cout << min(option1, option2) << endl;
    }   

    return 0;
}