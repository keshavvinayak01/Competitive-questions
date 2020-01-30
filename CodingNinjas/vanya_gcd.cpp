#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int get_increasing_gcd(int* a, int n){
    int dp[n][101];
    for(int i = 0 ; i < n; i++)
        for(int j = 0 ; j < 101; j++)
            dp[i][j] = 0;

    dp[0][a[0]] = 1;
    for(int i=1 ; i < n; i++){
        dp[i][a[i]]++;
        for(int j = 0 ; j < i; j++){
            if(a[i] > a[j]){
                for(int k = 1 ; k < 101; k++){
                    int ng = __gcd(a[i], k);
                    dp[i][ng] += dp[j][k]%MOD;
                    dp[i][ng] = dp[i][ng]%MOD;
                }
            }
        }
    }
    int res = 0;
    for(int i = 0 ; i < n; i++){
        res += dp[i][1];
        res = res%MOD;
    }
    return res%MOD;
}


int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i < n; i++)
        cin >> a[i];
    cout << get_increasing_gcd(a, n) << endl;
    return 0;
}