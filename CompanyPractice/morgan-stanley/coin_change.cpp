#include<bits/stdc++.h>
using namespace std;
#define take_input for(int i = 0 ; i < n ; i++) cin >>arr[i]; 

int main() {
    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n;
        int arr[n];
        take_input
        cin >> m;
        int* dp = new int[m+1];
        for(int i = 0 ; i <= m ; i++) dp[i] = 0;
        dp[0] = 1;
        for(int i = 0 ; i < n ; i++) {
            for(int j = arr[i]; j <= m ; j++) {
                dp[j] += dp[j - arr[i]];
            }
        }
        cout << dp[m] << endl;
        delete[] dp;
    }
    return 0;
}