#include<bits/stdc++.h>
typedef unsigned long long int lli;
#define MOD 1000000007
using namespace std;

bool rev(int a, int b) {return a > b;}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli t, n, k, end;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        vector<lli> arr(n);
        for(lli i = 0 ; i < n ; i++) cin >> arr[i];
        int idx = 0;
        while(idx < n) {
            if(distance(arr.begin() + idx, arr.end()) <= k) {
                reverse(arr.begin() + idx, arr.end());
                break;
            }
            reverse(arr.begin() + idx, arr.begin() + idx + k);
            idx += k;
        }
        for(int i = 0 ; i < n ; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}