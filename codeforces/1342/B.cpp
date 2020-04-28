#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, temp = INT_MAX;
    string s, ans;
    bool flag;
    cin >> t;
    while(t--) {
        cin >> s;
        ans = "";
        int i;
        for(i = 1 ; i <= 100; i++) {
            flag = true;
            for(int j = 0; j < s.size()-i ; i++) {
                if(s[j] != s[i + j]) {flag = false; break;}
            }
            if(flag) {temp = min(i, temp);break;}
        }
        if(temp == 1 || temp == 2) {cout << s << endl;continue;}
        ans += s[0];
        for(int i = 1; i < 2*s.size() ; i++) {
            if(ans[i-1] == '0') ans += "1";
            else                ans += "0";
        }        
        cout << ans << endl;
    }

    return 0;
}