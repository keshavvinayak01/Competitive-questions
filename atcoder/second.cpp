#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n, k, temp;
    cin >> n >> k;
    lli sum = 0;
    for(int i = 0 ; i < k ; i++) {
        cin >> temp;
        sum += temp;
    }
    if(sum > n) cout << -1 << endl;
    else cout << n - sum << endl;
    return 0;
}