/*
Given two weights of a and b units, in how many different ways you can achieve 
a weight of d units using only the given weights? Any of the given weights can be 
used any number of times (including 0 number of times).
*/

// ((d%a) * ModInverse(b, a))%a

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Triplet {
    ll x, y, gcd;
};

Triplet extendedEuclid(ll a, ll b) {
    if(b == 0) {
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;  
        ans.y = 0;
        return ans;
    }
    Triplet smallAns = extendedEuclid(b, a%b);
    Triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b)*smallAns.y;
    return ans;
}


ll modInverse(ll a, ll b) {
    ll x = extendedEuclid(a, b).x;
    return (x % b + b)%b;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll a, b, d;
        cin >> a >> b >> d;
        ll g = __gcd(a,b);
        if(d%g) {
            cout << 0 << endl;
            continue;
        }

        if(d == 0) {
            cout << 1 << endl;
            continue;
        }

        a /= g;
        b /= g;
        d /= g;

        ll y1 = ((d%a) * modInverse(b, a)) % a;
        if(d < y1*b) {
            cout << 0 << endl;
            continue;
        }
        ll n = ((d/b) - y1)/a;

        cout << n + 1 << endl;
    }
    return 0;
}