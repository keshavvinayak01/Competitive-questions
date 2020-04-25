// mod = 10**9 + 7
// for ii in range(int(input())):
//   n , a = map(int , input().split())
//   s = 0
//   p = 1
//   for i in range(1, n+1):
//     a = (a *p) % mod
//     s += pow(a , 2*i -1, mod) #% mod
//     #print(s)
//     p = pow(a, 2*i -1, mod)
//     #print(a, p)
//   print(s%mod)

#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

lli power(lli a, lli n) {
    lli res = 1;
    while(n) {
        if(n & 1)
            res = (res * a) % MOD;
        n >>= 1;
        a = (a * a) % MOD;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli t, n, a, sx, px;
    cin >> t;
    while(t--) {
        cin >> n >> a;
        sx = 0;
        px = 1;
        for(int i = 1; i <= n ; i++) {
            a = (a * px) % MOD;
            px = power(a, 2*i - 1);
            sx += px;
        }
        cout << sx % MOD << endl;
    }

    return 0;
}