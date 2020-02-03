#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int curr;
        int ans = 0;
        for(int i = 0 ; i < s.size() ; i++) {
            curr = s[i] - '0';
            if(curr > 9 || curr < 0) {
                ans = -1;
                break;
            }
        }
        if(ans != 0) {
            cout << ans << endl;
            continue;
        }
        cout << s << end
    }
    return 0;
}