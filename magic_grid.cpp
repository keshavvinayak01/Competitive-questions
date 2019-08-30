#include<bits/stdc++.h>
using namespace std;

int min_cost_iterative(int **input, int m, int n){
    int** dp = new int*[m];
    for(int i=0; i < m; i++){
        dp[i] = new int[n];
    }
    dp[m-1][n-1] = 0;
    dp[0][0] = 0;
    dp[m-2][n-1] = 0 - input[m-2][n-1] + 1;
    if(dp[m-2][n-1] <= 0) dp[m-2][n-1] = 1;
    dp[m-1][n-2] = 0 - input[m-1][n-2] + 1;
    if(dp[m-1][n-2] <= 0) dp[m-1][n-2] = 1;
    for(int i=m-3; i >=0; i--){
        dp[i][n-1] = dp[i+1][n-1] - input[i][n-1];
        if(dp[i][n-1] <= 0) dp[i][n-1] = 1;
    }
    for(int j=n-3; j >=0; j--){
        dp[m-1][j] = dp[m-1][j+1] - input[m-1][j];
        if(dp[m-1][j] <= 0) dp[m-1][j] = 1;
    }

    for(int i=m-2; i >=0; i--){
        for(int j = n-2; j >=0; j--){
            dp[i][j] = min(dp[i+1][j] - input[i][j], dp[i][j+1] - input[i][j]);
            if(dp[i][j] <= 0) dp[i][j] = 1; 
        }
    }
    // for(int i = m - 2; i >= 0 ; i--){
    //     for(int j = n - 2; j >=0; j--){
    //         dp[i][j] = input[i][j] + min(dp[i+1][j],dp[i][j+1]));
    //     }
    // }
    int ans =  dp[0][0];
    for(int i=0; i < m; i++){
        delete[] dp[i];
    }
    delete[] dp;
    return ans;
}


int main(){

    int t;
    cin >> t;
    while(t--){
        int r, c;
        cin >> r >> c;
        
        int** a = new int*[r];
        for(int i=0; i < r; i++)
            a[i] = new int[c];

        for(int i=0;i<r;i++)
            for(int j=0;j < c;j++)
                cin >>a[i][j];
        
        cout << min_cost_iterative(a, r, c) << endl;
    }

    return 0;
}