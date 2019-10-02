#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int solve(string s){
    int n = s.size();
    int last[100000];
    memset(last, -1, sizeof(last));
    int dp[n+1];
    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        dp[i] = (2*(dp[i-1]%MOD))%MOD;
        if(last[s[i-1]] != -1){
            dp[i] = (dp[i]%MOD - dp[last[s[i-1]]])%MOD;
        }
        last[s[i-1]] = i-1;
    }
    return dp[n]%MOD;
}


int main(){
    int n;
    cin >> n;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        cout << solve(s) << endl;
    }

    return 0;
}