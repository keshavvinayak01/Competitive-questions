#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n, q, c, ans;
    cin >> t;
    while(t--) {
        int counts[26];
        cin >> n >> q;
        string arr;
        cin >> arr;
        memset(counts, 0, sizeof(counts));
        for(int i = 0 ; i < arr.size() ; i++) counts[arr[i] - 'a']++;
        while(q--) {
            ans = 0;
            cin >> c;
            for(int i = 0 ; i < 26 ; i++) 
                if(counts[i] > 0)
                    ans += max(0, counts[i] - c);
            cout << ans << endl;
        }
    }

    return 0;
}