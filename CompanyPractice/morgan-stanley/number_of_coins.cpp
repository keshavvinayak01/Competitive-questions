#include<bits/stdc++.h>
using namespace std;
#define take_input for(int i = 0 ; i < n ; i++) cin >>arr[i]; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    int v, n;
    cin >> t;
    while(t--) {
        cin >> v >> n;
        int arr[n];
        int dp[v+1];
        for(int i = 0 ; i <= v ; i++) dp[i] = 1000001;
        dp[0] = 0;
        take_input
        for(int j = 0 ; j < n ; j++) {
            for(int i = arr[j]; i <= v ; i++) {
                dp[i] = min(dp[i], dp[i - arr[j]] + 1);
            }
        }
        if(dp[v] == 1000001) cout << -1 << endl;
        else cout << dp[v] << endl;
    }
    return 0;
}