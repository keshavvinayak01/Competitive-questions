#include<bits/stdc++.h>
using namespace std;

int getMaxSum(int n, int arr[], int* dp) {
    for(int i = 1 ; i < n ; i++) {
        for(int j = i-1 ; j >= 0 ; j--) {
            if(arr[j] < arr[i]) {
                dp[i] = max(dp[i], arr[i] + dp[j]);
            }
        }
    }
    int max_ans = INT_MIN;
    for(int i = 0 ; i < n ; i++) max_ans = max(max_ans, dp[i]);
    return max_ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        int* dp = new int[n];
        for(int i = 0 ; i < n ; i++) dp[i] = arr[i];
        cout << getMaxSum(n, arr, dp) << endl;
        delete[] dp;
    }

    return 0;
}