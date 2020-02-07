#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int arr[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        int curr_max = arr[n-1];
        vector<int> leaders;
        for(int i = n-2; i >= 0 ; i--) {
            if(arr[i] >= curr_max) {
                leaders.push_back(arr[i]);
                curr_max = arr[i];
            }
        }
        for(int i = leaders.size()-1; i >= 0; i--) cout << leaders[i] << " ";
        cout << arr[n-1] << endl;
    }

    return 0;
}