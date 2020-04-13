#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        bool ans = false;
        int init = -1;
        for(int i = s.length() - 1; i >= 0 ; i--) {
            if(s[i] != 'z') {
                s[i] = char(s[i]) + 1;
                init = i;
                break;
            }
        }
        if(init != -1) {
            for(int i = 0; i < s.length() ; i++) {
                if(i != init && s[i] != 'a') {
                    s[i] = char(s[i]) - 1;
                    ans = true;
                    break;
                }
            }
        }
        lli hash_val = 0;
        for(int i = 0 ; i < s.length(); i++) {
            hash_val += s[i] - 'a';
        }
        if(!ans) cout << -1 << endl;
        else     cout << hash_val << " " << s << endl;
    }

    return 0;
}