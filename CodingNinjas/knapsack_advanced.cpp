#include<bits/stdc++.h>
using namespace std;

int knapsack_recursive(int* weights,int* values,int n,int maxWeight,int s,int** dp){
    
    if(s>=n || maxWeight<=0)
        return 0;
    
    if(dp[s][maxWeight]>0)
        return dp[s][maxWeight];
    
    int option1=0;
    if(weights[s]<=maxWeight){
        option1=values[s]+knapsack_recursive(weights,values,n,maxWeight-weights[s],s+1,dp);
    }
    int option2=knapsack_recursive(weights,values,n,maxWeight,s+1,dp);
    dp[s][maxWeight]= max(option1,option2);
    return dp[s][maxWeight];
}

int knapsack_iterative(int* weights, int* values, int w, int n){
    int** dp = new int*[n+1];
    for(int i = 0 ; i <=n ; i++)
        dp[i] = new int[w+1];
    for(int i = 0; i <=w; i++)
        dp[0][i] = 0;
    for(int i = 0 ; i<=n; i++)
        dp[i][0] = 0;

    for(int i = 1; i <=n; i++){
        for(int j = 0; j <=w; j++){
            dp[i][j] = dp[i-1][j];
            if(weights[i-1] <= j){
                dp[i][j] = max(dp[i][j], values[i-1] + dp[i-1][j-weights[i-1]]);
            }
        }
    }
    int ans = dp[n][w];
    for(int i = 0; i <= n; i++)
        delete[] dp[i];
    delete[] dp;
    return ans;
}

int main(){ 
    int n;
    cin >> n;
    int* weights = new int[n];
    int* values = new int[n];
    for(int i = 0 ; i < n; i++) cin >> weights[i];
    for(int i = 0 ; i < n; i++) cin >> values[i];
    int w;
    cin >> w;
    int** dp = new int*[n+1];
    for(int i = 0 ; i <=n ; i++)
        dp[i] = new int[w+1];
    cout << knapsack_recursive(weights, values, n, w, 0, dp) << endl;
    // cout << knapsack_iterative(weights, values, w, n) << endl;
    
    return 0;
}