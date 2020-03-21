#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, s, n;
    cin >> t >> s;
    while(t--) {
        cin >> n;
        int a[n], b[n];
        map<lli, int> counts1;
        vector<int> distinct;
        map<lli, int> counts2;
        int max_a = INT_MIN;
        for(int i = 0 ; i < n ; i++) {
            cin >> a[i];
            max_a = max(max_a, a[i]);
            counts1[a[i]]++;
        };
        for(int i = 0 ; i < n ; i++) {
            if(counts1[a[i]] == 1) distinct.push_back(a[i]);
        }
        for(int i = 0 ; i < n ; i++){
            cin >> b[i];
            counts2[b[i]]++;
        }
        bool ans = true;
        for(int i = 0 ; i < n ; i++) {
            if(b[i] <= max_a) {
                ans = false;
                break;
            }
        }
        if(!ans) {
            cout << "NO\n";
        }
        else {
            int count = 0;
            for(int i = 0 ; i < distinct.size() ; i++) {
                if(counts2[distinct[i]] == 1) count++;
                else break;
            }
            if(count == distinct.size() && distinct.size()> 0) cout << "YES\n";
            else           cout << "NO\n";
        }
            
            
    }

    return 0;
}