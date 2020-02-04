#include<bits/stdc++.h>
using namespace std;

char nonRepeatingChar(string s, int n) {
    string new_string = "";
    map<char, int> counts;
    for(int i = 0 ; i < n ; i++) {
        counts[s[i]]++;
    }
    for(int i = 0 ; i < n ; i++) {
        if(counts[s[i]] == 1) {
            return s[i];
        }
    }
    char temp_char = '+';
    return temp_char;
}

int main() {
    int t, n;
    char ans;
    string s;
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> s;
        ans = nonRepeatingChar(s, n);
        if(ans == '+') cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}