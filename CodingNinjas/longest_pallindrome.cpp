#include<bits/stdc++.h>
using namespace std;

int lps(string s) {
    int maxLength = 0;
    int n = s.length();
    for(int i = 0 ; i < n ; i++) {
        // Odd Length
        int l = i;
        int r = i;
        while(l >= 0 && r < n && s[l] == s[r]) {
            maxLength = max(maxLength, r-l+1);
            l--; r++;
        }
        l = i;
        r = i+1;
        while(l >= 0 && r < n && s[l] == s[r]) {
            maxLength = max(maxLength, r-l+1);
            l--; r++;
        }
    }
    return maxLength;
}

int main() {
    string s;
    cin >> s;
    cout << lps(s) << endl;
    return 0;
}