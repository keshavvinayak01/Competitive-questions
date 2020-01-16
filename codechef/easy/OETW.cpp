#include<bits/stdc++.h>
typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

int main() {
    fastio
    int t;
    cin >> t;
    ll counts[4];
    counts[0] = 0;
    while(t--) {
        counts[1] = counts[2] = counts[3] = 0;
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0 ; i < n ; i++) {
            cin >> arr[i];
            counts[arr[i]]++;
            counts[3] += arr[i]; 
        }
        if(counts[1] > 0) cout << counts[3] << endl;
        else cout << counts[3]/2 << endl;
    }
    return 0;
}