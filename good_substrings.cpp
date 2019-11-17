#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    int* dp = new int[n-k];
    dp[0] = 0;
    for(int i = 0; i < k; i++) {
        dp[0] += s[0] - '0';
    }
    for(int i = 1; i < n-k; i++) {
        dp[i] += dp[i-1] + (s[i+k-1] - s[i-1]);
    }
    int operations = 0;
    for(int i = 0 ; i < n-k; i++) {
        if(dp[i] > m) {
            int init = i;
            int size = 0;
            i++;
            while(dp[i] > m && size <= k) {
                size++;
                i++;
            }
            s[init + size + 1] = '0';
            operations++;
        }
    }
    cout << operations << endl << s << endl;
    return 0;
}