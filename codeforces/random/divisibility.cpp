#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, rem;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        rem = a % b;
        if(rem == 0) cout << 0 << endl;
        else {
            cout << b - rem << endl;
        }
    }

    return 0;
}