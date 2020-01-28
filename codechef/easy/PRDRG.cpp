#include<bits/stdc++.h>
typedef unsigned long long int lli;
using namespace std;

int main() {
    lli t, n, j;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << ((1 << n) - (1 - 2*(n & 1)))/3 << " " << (1 << n) << " " ;
    }
    return 0;
}