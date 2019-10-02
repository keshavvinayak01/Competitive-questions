#include<bits/stdc++.h>
using namespace std;
int ***dp = new int**[31];

int get_profit(int* a, int n, int k, int transaction){
    if(n <= 0 || k < 0){
        return 0;
    }
    int option1 = get_profit(a+1, n-1, k, transaction);
    int option2;
    if(transaction == 1){
        option2 = a[0] + get_profit(a+1, n-1, k-1, 0);
    }
    else if(k > 0){
        option2 = get_profit(a+1, n-1, k, 1) - a[0] ;
    }
    cout << option1 << " " << option2 << endl;
    return max(option1, option2);
}

int main(){

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> k;
        cin >> n;
        int a[n];
        // for(int i=0; i <= 30; i++){
        //     dp[i] = new int*[10];
        //     for(int j = 0; j < 10; j++){
        //         dp[i][j] = new int[2];
        //         dp[i][j][0] = dp[i][j][1] = 0;
        //     }
        // }
        
        for(int i = 0; i < n; i++) cin >> a[i];
        cout <<  get_profit(a, n, k, 0) << endl;
        // for(int i = 0 ; i <= n; i++){
        //     for(int j=0; j < k; j++){
        //         cout << dp[i][j][0] << "," << dp[i][j][1] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for(int i = 0; i <= 30; i++){
        //     for(int j=0; j < 10; j++){
        //         delete[] dp[i][j];
        //     }
        //     delete[] dp[i];
        // }
        // delete[] dp;
    }
    return 0;
}