#include<bits/stdc++.h>
using namespace std;

int get_cost(int* ass, int n, int x, int* cap, int** dp){
    if(n <= 0){
        return 0;
    }
    if(dp[n][x] > 0) return dp[n][x];
    if(x == 0){
        dp[n][x] = ass[0] + get_cost(ass+1, n-1, x+1, cap+1, dp); 
        return dp[n][x];
    }
    else if(x == n){
        dp[n][x] = cap[0] + get_cost(ass+1, n-1, x-1, cap+1, dp);
        return dp[n][x];
    }
    else{
        int option1 = ass[0] + get_cost(ass+1, n-1, x+1, cap+1, dp);
        int option2 = cap[0] + get_cost(ass+1, n-1, x-1, cap+1, dp);
        dp[n][x] = min(option1, option2);
        return dp[n][x];
    }
}

int main(){
    int n;
    cin >> n;
    int ass[n], cap[n];
    for(int i =0; i < n; i++){
        cin >> cap[i] >> ass[i];
    }
    int** dp = new int*[10000];
    for(int i = 0 ; i < 10000; i++){
        dp[i] = new int[10000];
    }
    cout << get_cost(ass, n, 0, cap, dp) << endl;

    return 0;
}