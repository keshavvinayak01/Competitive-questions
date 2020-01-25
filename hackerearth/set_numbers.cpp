#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;

int countpow(int n) {
    int count = 0;
    while(n > 0) {
        n /= 2;
        count++;
    }
    return count;
}

int main() {    
    lli t, n, ans1, ans2, power;
    cin >> t;
    while(t--) {
        cin >> n;
        ans1 = pow(2, (int)log2(n+1)) - 1 ;

        power = int(log2(n+1));
        ans2 = pow(2, power);
        int curr = 0;
        while(ans2 <= n) {
            ans2 += pow(2, curr);
            curr++;
        }
        if(ans2 > n) ans2 -= pow(2, curr);

        if(countpow(ans1) > countpow(ans2))
            cout << ans1 << endl;
        else cout << ans2 << endl;
    }
    return 0;
}