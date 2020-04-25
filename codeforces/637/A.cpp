#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n, a, b, c, d, s, f;
    bool ans;
    cin >> t;
    while(t--) {
        ans = false;
        cin >> n >> a >> b >> c >> d;
        s = c - d;
        f = c + d;
        for(int i = (a - b)*n ; i <= (a + b)*n ; i++) {
            if(i >= s && i <= f) {
                ans = true;
                cout << "Yes\n";
                break;  
            }
        }
        if(!ans) cout << "No\n";
    }

    return 0;
}