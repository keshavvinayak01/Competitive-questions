#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, max_dist = -1;
        cin >> n;
        int arr[n], cap[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        for(int i = 0 ; i < n ; i++) cin >> cap[i];
        for(int i = 0 ; i < n ; i++) max_dist = max(max_dist, 2 * arr[i]);
        int dp[max_dist + 1];
        sort(arr, arr + n);
        sort(cap, cap + n);
        
        for(int i = 2 ; i <= max_dist ; i++) {
            if()
        }
    }

    return 0;
}