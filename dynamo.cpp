#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll highest = pow(10, n);
        ll a, b, c, d, e, s;
        cin >> a;
        s = 2*highest + a;
        cout << s << endl;
        fflush(stdout);
        cin >> b;
        c = highest - b;
        cout << c << endl;
        fflush(stdout);
        cin >> d;
        e = s - a - b - c - d;
        cout << e << endl;
        fflush(stdout);
        int v;
        cin >> v;
        if(v == -1) return 0;
    }
    return 0;
}