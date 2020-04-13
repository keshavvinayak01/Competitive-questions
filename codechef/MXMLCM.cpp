#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

lli gcd(lli a, lli b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}

lli lcm(lli a, lli b) {
    return (a*b)/gcd(a, b);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli t;
    cin >> t;
    while(t--) {
        lli n, m;
        lli max_lcm = -1;
        cin >> n >> m;
        lli arr[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        lli curr_lcm = arr[0];
        for(int i = 1 ; i < n ; i++) {
            curr_lcm = lcm(curr_lcm, arr[i]);
        }
        lli new_lcm = curr_lcm;
        lli curr_max = curr_lcm;
        for(int i = 1 ; i <= m ; i++) {
            new_lcm = lcm(i, curr_lcm);
            if(new_lcm > curr_max || max_lcm == -1) {
                max_lcm = i;
                curr_max = new_lcm;
            }
        } 
            // if(prime[i] && i != curr_lcm) max_lcm = i;
        cout << max_lcm << endl;
    }

    return 0;
}