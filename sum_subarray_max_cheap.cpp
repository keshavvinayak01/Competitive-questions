#include<bits/stdc++.h>
using namespace std;

int **dp = new int*[50001];

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
        dp[i] = new int[n + 1];
    }

    for(int i = 0 ; i < n ; i++){
        dp[i][i] = arr[i];
        for(int j = i+1; j < n; j++) 
            dp[i][j] = max(dp[i][j-1] + arr[j], arr[j]);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0 ; j < n; j++) cout << dp[i][j] << " ";
        cout << endl;
    }
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << max(dp[a-1][b-2], dp[a-1][b-1]) << endl;
    }
    return 0;
}