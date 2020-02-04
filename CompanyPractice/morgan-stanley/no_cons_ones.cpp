#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

lli dp[101];

lli fib(lli n) {
    if(dp[n] > 0) return dp[n];

    dp[n] = (fib(n-1) % MOD + fib(n-2) % MOD) % MOD;
    return dp[n];
}


int main() {
    for(int i = 0 ; i <= 100; i++) dp[i] = 0;
    dp[0] = 1;
    dp[1] = 2;
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        if(dp[n] > 0) cout << dp[n] << endl;
        else cout << fib(n) << endl;
    }
}