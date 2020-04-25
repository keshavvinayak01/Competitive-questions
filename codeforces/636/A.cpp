#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli t, n, lim;
    cin >> t;
    while(t--) {
        cin >> n;
        lim = log2(n) + 2;
        for(lli i = 2 ; i < lim; i++) {
            if(n % (lli(pow((lli)2, i)) - 1) == 0) {
                cout << int(n)/(int(pow(2, i) - 1)) << endl;
                break;
            }
        }
    }

    return 0;
}