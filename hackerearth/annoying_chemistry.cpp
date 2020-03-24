#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

lli gcd(lli m, lli n) {
    if(n == 0) return m;
    return gcd(n, m%n);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli x, y, p, q;
    cin >> x >> y >> p >> q;
    lli b1, b2, b3;
    if(p % x == 0) b1 = (p/x);
    if(q % y == 0) b2 = (q/y);
    if(p % x == 0 && q % y == 0) cout << b1 << " " << b2 << " " << 1 << endl;
    else {
        
    }
    return 0;
}