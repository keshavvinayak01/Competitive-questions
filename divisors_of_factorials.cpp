/*
    Given a number, find the total number of divisors of the factorial of the number.
    Since the answer can be very large, print answer modulo 10^9+7.
*/

#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll getPower(int p, int k, int n) {
    ll sum = 0;
    for(int i = 1; i <= k; i++) {
        sum += n/pow(p, i) ;
        sum = sum % MOD;
    }
    return sum;
}

void getPrime(bool* prime, int n) {
    prime[0] = false;
    prime[1] = false;
    for(int i = 2 ; i*i <= n; i++) {
        if(prime[i]) {
            for(int j = i*i; j <= n; j += i) {
                prime[j] = false;
            }
        }    
    } 
}

ll divisors(int n) {
    bool* prime = new bool[n + 1];
    for(int i = 0 ; i <= n ; i++) prime[i] = true; 
    getPrime(prime, n);
    ll ans = 1;
    for(int i = 2 ; i <= n ; i++) {
        if(prime[i]) {
            int k = log(n)/log(i);
            ans *= (getPower(i, k, n) + 1)%MOD;
            ans = ans%MOD;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << divisors(n) << endl;
    }
    return 0;
}