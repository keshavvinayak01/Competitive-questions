#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n, temp, ans, count, k;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> arr(100001, 0);
        for(int i = 0 ; i < n ; i++) {
            cin >> temp;
            arr[temp]++;
        }
        cin >> k;
        count = 0;
        for(int i = 1 ; i <= 100000 ; i++) {
            if(arr[i] > 0) count += arr[i];
            if(count >= k) {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}