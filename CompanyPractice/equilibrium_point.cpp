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
        int* arr = new int[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        int* sums = new int[n];
        sums[0] = arr[0];
        for(int i = 1 ; i < n ; i++) {
            sums[i] = sums[i-1] + arr[i];
        }
        int ans = -1;
        for(int i = 1 ; i < n ; i++) {
            if(sums[i-1] == sums[n-1] - sums[i]) {
                ans = i + 1; break;
            }
        }
        if(n == 1) cout << 1 << endl;
        else cout << ans << endl;
    }

    return 0;
}