#include<bits/stdc++.h>
using namespace std;


int editDistances(char* s1, char* s2, int **dp, int m, int n){
    if(m == 0 ){
        return n;
    }
    if(n == 0){
        return m;
    }
    if(dp[m][n] > -1) return dp[m][n];
    int ans;
    if(s1[0] == s2[0]){
        ans = editDistances(s1+1, s2+1, dp, m-1,n-1);
    }
    else{
        int option1 = 1 + editDistances(s1+1, s2, dp, m-1, n);
        int option2 = 1 + editDistances(s1+1, s2+1, dp, m-1, n-1); 
        int option3 = 1 + editDistances(s1, s2+1, dp, m-1, n-1);
        ans = min(option1, min(option2, option3));
    }
    dp[m][n] = ans;
    return ans;
}

int editDistance(string s1, string s2, int** dp, int m, int n){
    char s12[m+1], s22[n+1];

    for(int i = 0; i < m; i++)
        s12[i] = s1[i];
    for(int i = 0; i < n; i++)
        s22[i] = s2[i];
    return editDistances(s12, s22, dp, m, n);
}

int main(){ 
    string s1, s2;
    cin >> s1;
    cin >> s2;
    
    cout << editDistance(s1, s2, dp, m, n) << endl;
    return 0;
}