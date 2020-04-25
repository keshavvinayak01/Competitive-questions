#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli t;
    cin >> t;
    while(t--) {
        lli n;
        cin >> n;
        if(n % 2 == 0) cout << n/2 - 1 << endl;
        else           cout << n/2 << endl;
    }

    return 0;
}