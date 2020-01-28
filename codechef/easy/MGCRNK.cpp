#include<bits/stdc++.h>
typedef long long int lli;
#define MIN_VAL -5000
using namespace std;

lli maxPossiblePoints(int arr[100][100], int row, int col, int n, int dp[100][100]) {
    
    if(row < 0 || col < 0 || row >= n || col >= n) return 0;
    if(row == n-1 && col == n-1) return 0;

    if(dp[row][col] > MIN_VAL) return dp[row][col];
    
    lli option1 = arr[row][col] + maxPossiblePoints(arr, row+1, col, n, dp);
    lli option2 = arr[row][col] + maxPossiblePoints(arr, row, col+1, n, dp);
    
    dp[row][col] = max(option1, option2);
    return dp[row][col];
}

int main() {
    lli t, n, ans;
    cin >> t;
    while(t--) {
        cin >> n;
        int arr[100][100], dp[100][100];
        
        for(int i = 0 ; i < n ; i++)
            for(int j = 0; j < n ; j++) dp[i][j] = MIN_VAL;
        
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++) cin >> arr[i][j];

        ans = maxPossiblePoints(arr, 0, 0, n, dp);
        if(ans < 0) {
            cout <<"Bad Judges\n";
        }
        else {
            cout << ans << ".000000" << endl;
        }
    }

    return 0;
}