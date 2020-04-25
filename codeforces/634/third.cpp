#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        int counts[n+1];
        memset(counts, 0 , sizeof(counts));
        if(n == 1) {
            cout << 0 << endl;
            continue;
        }
        for(int i = 0 ; i < n ; i++) counts[arr[i]]++;
        // Count all distinct and maximum amongst repeating
        int dc = 0, rc = INT_MIN; 
        for(int i = 0 ; i <= n ; i++) {
            if(counts[i] > 0) dc++;
            rc = max(rc, counts[i]);
        }
        if(rc > 1) dc--;
        if(rc > dc + 1) cout << dc + 1 << endl;
        else cout << min(dc, rc) << endl;
    }

    return 0;
}