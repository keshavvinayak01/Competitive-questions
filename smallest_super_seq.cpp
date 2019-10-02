#include<bits/stdc++.h>
using namespace std;


int lcs(char* s1, char* s2, int m, int n, int** dp){
    if(s1[0] == '\0' || s2[0] == '\0'){
        return 0;
    }
    if(s1[0] == s2[0]){
        dp[m][n] =  1 + lcs(s1 + 1, s2 + 1, m-1, n-1, dp);
        return dp[m][n];
    }
    else{
        int option1 = lcs(s1, s2 + 1, m, n-1, dp);
        int option2 = lcs(s1+1, s2, m-1, n, dp);
        dp[m][n] =  max(option1, option2);
        return dp[m][n];
    }
}

int main(){
    char s1[] = "ab";
    char s2[] = "ac";
    int m = strlen(s1);
    int n = strlen(s2);
    int **dp = new int*[1000];
    for(int i = 0 ; i < 1000 ; i ++) dp[i] = new int[1000];
    int lcl = lcs(s1, s2, m, n, dp);
    if(lcl == 0){
        cout << m + n << endl;
    } 
    else{
        cout << max(m,n) + (min(m,n) - lcl) << endl;
    }
        
    return 0;
}