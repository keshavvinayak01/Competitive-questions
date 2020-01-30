#include<bits/stdc++.h>
using namespace std;


int getHappiness(char* s1, char* s2, int m, int n, int k, vector<vector<vector<int>>> dp){
    if(m < 0 || n < 0) return INT_MIN;
    if(k == 0) return 0;
    if(dp[m][n][k] > 0) return dp[m][n][k];
    int ans;
    if(s1[0] == s2[0]){
        int option1 = int(s1[0]) + getHappiness(s1+1, s2+1, m-1, n-1, k - 1, dp);
        int option2 = getHappiness(s1, s2+1, m, n-1, k, dp);
        int option3 = getHappiness(s1+1, s2, m-1 ,n , k, dp);
        ans =  max(option1, max(option2, option3));
    }
    else{
        int option1 = getHappiness(s1+1, s2, m-1, n, k, dp);
        int option2 = getHappiness(s1, s2+1, m, n-1, k, dp);
        ans =  max(option1, option2);
    }
    
    dp[m][n][k] = ans;
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        string s1t, s2t;
        cin >> s1t;
        cin >> s2t;
        cin >> k;
        int m = s1t.length();
        int n = s2t.length();
        vector<vector<vector<int>>> dp(m+1);
        for(int i = 0 ; i <= m; i++){
            dp[i].resize(n+1);
            for(int j = 0 ; j <= n; j++){
                dp[i][j].resize(k+1);
            }
        }
        char s1[m+1], s2[n+1];
        strcpy(s1, s1t.c_str());
        strcpy(s2, s2t.c_str());
        cout << max(0,getHappiness(s1, s2, m, n, k, dp)) << endl;
    }
    return 0;
}