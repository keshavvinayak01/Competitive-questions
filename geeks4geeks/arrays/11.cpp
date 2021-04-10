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
        int smallest[n], largest[n];
        smallest[0] = arr[0];
        largest[n-1] = arr[n-1];
        for(int i = 1 ; i < n ; i++) 
            smallest[i] = min(arr[i], smallest[i-1]);
        
        for(int i = n-2 ; i >= 0; i--) 
            largest[i] = max(arr[i], largest[i+1]);
        
        vector<int> ans;
        for(int i = 1 ; i < n-1; i++) {
            if(arr[i] > smallest[i] && arr[i] < largest[i]) {
                ans = {smallest[i], arr[i], largest[i]};
                // return ans;
                cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
                break;
            }
        }
    }
    return 0;
}