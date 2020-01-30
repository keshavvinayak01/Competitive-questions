#include<bits/stdc++.h>
using namespace std;

void clear_dp(int** dp){
    for(int i = 0; i < 40; i++)
        for(int j = 0 ; j < 40; j++) dp[i][j] = 0;
}

int get_max_ans(int o, int c, int size, bool* arr, int** dp){
    if(o > size/2 || c > size/2) return 0;
    
    if(o == size/2 && c == size/2) return 1;

    if(dp[o][c] > 0) return dp[o][c];
    if(o == c || arr[o+c+1] == true){
        dp[o][c] = get_max_ans(o+1, c, size, arr, dp);
        return dp[o][c];
    }

    else if(o == size/2){
        dp[o][c] = get_max_ans(o, c+1, size, arr, dp);
        return dp[o][c];
    }

    else {
        dp[o][c] = get_max_ans(o, c+1, size, arr, dp) + get_max_ans(o+1, c, size, arr, dp);
        return dp[o][c];
    }
}

int main(){

    int d;
    cin >> d;
    int n, k;
    int x;
    int **dp = new int*[40];
    for(int i = 0; i < 40; i++) dp[i] = new int[40];
    while(d--){
        cin >> n >> k;
        bool arr[2*n + 1];
        clear_dp(dp);
        for(int i = 0; i <= 2*n; i++) arr[i] = false;
        for(int i = 0 ; i < k; i++){
            cin >> x;
            arr[x] = true;
        }
        cout << get_max_ans(0, 0, 2*n, arr, dp) << endl;
    }

    return 0;
}