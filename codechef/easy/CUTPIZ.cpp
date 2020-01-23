#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, min_cut, n;
    cin >> t;
    while(t--) {
        min_cut = 0;
        cin >> n;
        int cuts[n];
        int sectors[n];
        for(int i = 0 ; i < n ; i++) cin >> cuts[i];
        for(int i = 0 ; i < n-1; i++) sectors[i] = cuts[i+1] - cuts[i];
        min_cut = sectors[0];
        sectors[n] = 360 - (cuts[n-1] - cuts[0]);
        for(int i = 1; i < n ; i++) {
            min_cut = __gcd(min_cut, sectors[i]);
        }
        cout << 360/min_cut - n << endl;
    }
    return 0;
}