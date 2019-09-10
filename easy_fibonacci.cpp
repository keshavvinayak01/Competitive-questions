#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    int x;
    ll dp[60];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2 ; i < 60; i++){
        dp[i] = (dp[i-1]%10 + dp[i-2]%10)%10;
    }
    // for(int i = 0 ; i < 60; i++) cout << dp[i] << " ";
    // cout << endl;
    while(t--){
        cin >> x;
        int max = log2(x);
        ll index_temp = pow(2,max);
        int index = index_temp%60 - 1;
        cout << dp[index]%10 << endl;
    }

    return 0;
}