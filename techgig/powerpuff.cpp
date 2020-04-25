#include<bits/stdc++.h>
typedef unsigned long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli n;
    cin >> n;
    lli req[n], quant[n];
    for(lli i = 0 ; i < n ; i++) cin >> req[i];
    for(lli i = 0 ; i < n ; i++) cin >> quant[i];
    lli ans = INT_MAX;
    for(lli i = 0 ; i < n ; i++) ans = min(ans, quant[i]/req[i]);
    cout << ans << endl;
    return 0;
}