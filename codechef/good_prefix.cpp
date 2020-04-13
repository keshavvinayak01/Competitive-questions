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
        int x, k;
        cin >> k >> x;
        map<char, int> counts;
        int max_now = 0;
        for(int i = 0 ; i < s.length(); i++) {
            if(counts[s[i]] == 0) {
                max_now += 1;
                counts[s[i]]++;
            }
            else {
                counts[s[i]]++;
                if(counts[s[i]] <= x) {
                    max_now += 1;
                } 
                else if(k > 0) {
                    k--;
                    counts[s[i]] -= 1;
                }
                else break;
            }
        }
        cout << max_now << endl;
        // for(int i = 0 ; i < s.length() ; i++) {
        //     cout << s[i] << " " << counts[s[i]] << endl;
        // }
    }

    return 0;
}