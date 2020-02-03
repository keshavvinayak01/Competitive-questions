#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int dp[n+1][m+1];
        dp[0][0] = 0;
        char s1[n], s2[m];
        cin >> s1;
        cin >> s2;
        for(int i = 0 ; i <= n ; i++) {
            for(int j = 0 ; j <= m ; j++) {
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        int ans = dp[0][0];
        for(int i = 0 ; i <= n ; i++) {
            for(int j = 0 ; j <= m ; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << endl;
    }
    return 0; 
}