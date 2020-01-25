#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli t, n, c, part1, ans;
    cin >> t;
    while(t--) {
        cin >> c >> n;
        if(n > c) {
            cout << c << endl;
            continue;
        }
        part1 = c/n - (n-1)/2;
        ans = (n*(2*part1 + n-1))/2;    
        while(part1 > 0 && ans > c) {
            part1--;
            ans = (n*(2*part1 + n-1))/2;    
        }
        if(part1 <= 0 || ans > c) {
            cout << c << endl;
            continue;
        }
        
        cout << c - ans << endl;
    }
    
    return 0;
}