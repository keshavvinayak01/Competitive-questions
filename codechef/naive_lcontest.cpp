#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    // ios::sync_with_stdio(false);cin.tie(0);
    lli t, a, b, c, d;
    int dp[1000022];
    for(int i = 0 ; i <= 1000000 ; i++) dp[i] = 0;
    dp[2020] = 553;
    for(int i = 2020; i >= 0 ; i -= 11) {
        dp[i - 5]  = dp[i] - 1;
        dp[i - 6]  = dp[i] - 2;
        dp[i - 11] = dp[i] - 3;
    }
    for(int i = 2020; i <= 100000 ; i += 11) {
        dp[i + 5]  = dp[i] + 1;
        dp[i + 6]  = dp[i] + 2;
        dp[i + 11] = dp[i] + 3;
    }
    for(int i = 1 ; i <= 1000000 ; i++) {
        dp[i] = max(dp[i-1], dp[i]);
    }
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cin >> c >> d;
        lli ans1 = dp[b];
        lli ans2 = dp[d];
        lli full_ans = ans2 - ans1;
        if(dp[b] > dp[b-1]) full_ans++;
        if(a > 2 && dp[b] > dp[b-1]) full_ans--;
        if(c < 2 && dp[d] > dp[d-1]) full_ans--;
        cout << full_ans << endl;
    }
    return 0;
}