#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli t;
    cin >> t;
    while(t--) {
        lli n, q;
        cin >> n >> q;
        lli arr[n], queries[q];
        for(lli i = 0 ; i < n ; i++) cin >> arr[i];
        for(lli i = 0 ; i < q ; i++) cin >> queries[i];
        for(lli i = 1 ; i < n ; i++) {
            arr[i] = max(arr[i], arr[i-1]);
        }
        for(lli i = 0 ; i < q ; i++) cout << arr[queries[i] - 1] << endl;
    }

    return 0;
}