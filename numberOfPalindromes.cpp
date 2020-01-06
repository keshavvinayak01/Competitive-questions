#include<bits/stdc++.h>
using namespace std;

int numberOfPalindromes(string s) {
    int n = s.length();
    int ans = 0;
    for(int i = 0 ; i < n ; i++) {
        // Odd Palindromes
        int l = i;
        int r = i;
        while(l >= 0 && r < n && s[l] == s[r]) {
            ans++;
            l--;
            r++;
        }
        // Even Palindromes
        l = i;
        r = i+1;
        while(l >= 0 && r < n && s[l] == s[r]) {
            ans++;
            l--;
            r++;
        }       
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << numberOfPalindromes(s) << endl;
    return 0;
}