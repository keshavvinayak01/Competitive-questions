#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        lli x, n, m, x1, x2;
        cin >> x >> n >> m;
        while(n--) {
            if(x/2 + 10 > x) break;
            else {
                x = x/2 + 10;
            }
        }
        while(m--) {
            x -= 10;    
        }
        if(x <= 0) cout << "YES\n";
        else       cout << "NO\n";
    }

    return 0;
}