#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int dp[100][100][2];

int f(int n, int k, int first){
    if(n == 1){
        if(k == 0){
            return 1;
        }
        return 0;
    }
    if(n <= 0) return 0;
    if(n < k) return 0;
    if(dp[n][k][first] > 0) return dp[n][k][first];
    if(first == 1){
        int ans = (f(n - 1, k - 1, 1)%MOD + f(n-1, k, 0)%MOD)%MOD;
        dp[n][k][first] = ans%MOD;
    }
    if(first == 0){
        int ans = (f(n-1, k, 0)%MOD + f(n-1,k,1)%MOD)%MOD;
        dp[n][k][first] = ans%MOD;
    }
    return dp[n][k][first]%MOD;
}


int main(){
    int t;
    cin >> t;
    int answers[t];
    int x = 0;
    while(t--){
        int i, n, k;
        cin >> i >> n >> k;
        cout << f(n, k, 0) + f(n, k, 1) << endl;
    }
    return 0;
}