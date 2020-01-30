#include<bits/stdc++.h>
using namespace std;

int **dp = new int*[101];

int spend_min_money(int** a, int n, int m, int** dp, int cur){
    if(n <= 0 || cur > m || cur < 0){
        return 0;
    }
    if(dp[n][cur] > 0) return dp[n][cur];
    for(int i = cur; i < m; i++){
        int option1 = a[n-1][cur] + spend_min_money(a, n-1, m, dp, cur);
        int option2 = a[n-1][cur] + spend_min_money(a, n-1, m, dp, cur-1);
        int option3 = a[n-1][cur] + spend_min_money(a, n-1, m, dp, cur+1);
        dp[n][cur] = min(option1, min(option2, option3));
    }
    return dp[n-1][cur];
}

int spend_min_money(int** a, int n, int m, int** dp){
    for(int i = 0; i < m; i++)
        dp[0][i] = a[0][i];
    for(int i = 1; i < n; i++){
        for(int j = 0 ; j < m; j++){
            if(j > 0 && j != m-1)
                dp[i][j] = a[i][j] + min(dp[i-1][j], min(dp[i-1][j+1], dp[i-1][j-1]));
            else if(j == 0)
                dp[i][j] = a[i][j] + min(dp[i-1][j], dp[i-1][j+1]);
            else if(j == m-1)
                dp[i][j] = a[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
        }
    }
    int ans = dp[n-1][0];
    for(int i = 0; i < m; i++){
        if(dp[n-1][i] < ans)
            ans = dp[n-1][i];
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    int** a = new int*[n];
    for(int i = 0; i < n; i++){
        a[i] = new int[m];
    }
    for(int i = 0; i <= 100; i++){
        dp[i] = new int[101];
    }
    
    
    for(int i = 0 ; i < n; i++)
        for(int j = 0 ; j < m; j++)
            cin >> a[i][j];
    
    // cout << spend_min_money(a, n, m, dp, 0) << endl;
    cout << spend_min_money(a, n, m, dp) << endl;
    return 0;
}