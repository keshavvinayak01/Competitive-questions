#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    ll fib[120];
    fib[0] = 0;
    fib[1] = 1;
    
    for(int i = 2 ; i <= 120 ; i++)
        fib[i] = fib[i-1] + fib[i-2];

    while(t--) {
        ll n;
        cin >> n;
        int i;
        for(i = 2 ; i <= 120 ; i++) {
            if(fib[i] > n) break;
        }
        cout << i - 2 << endl;
    }   
    return 0;
}