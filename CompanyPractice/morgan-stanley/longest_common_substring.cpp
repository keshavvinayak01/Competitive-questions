#include<bits/stdc++.h>
using namespace std;
int** dp = new int*[101];

int getMaxLength(char* s1, char* s2, int count) {
    if(s1[0] == '\0' || s2[0] == '\0') return 0;
    int res = count;
    if(s1[0] == s2[0]) {
        res = max(res, getMaxLength(s1 + 1, s2 + 1, count+1));        
    }
    int option1 = getMaxLength(s1 + 1, s2, 0);
    int option2 = getMaxLength(s1, s2 + 1, 0);
    res = max(res, max(option1, option2));
    
    return res;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        for(int i = 0 ; i <= 100; i++) {
            dp[i] = new int[101];
            for(int j = 0 ; j <= 100; j++) dp[i][j] = -1;
        }
        int n, m;
        cin >> n >> m;
        char s1[n], s2[m];
        cin >> s1;
        cin >> s2;
        if(s1[0] == s2[0])
            cout << getMaxLength(s1, s2, 0) +1 << endl;
        else 
            cout << getMaxLength(s1, s2, 0) << endl;
    }
    return 0; 
}