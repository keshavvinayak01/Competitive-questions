// from math import * 
// def bruh(n, k): 
//   a = list() 
//   while n % 2 == 0: 
//     a.append(2) 
//     n = n // 2
//   for i in range(3, ceil(sqrt(n)), 2): 
//     while n % i == 0: 
//       n = n / i; 
//       a.append(i) 
//   if n > 2: 
//     a.append(n) 
//   if len(a) < k: 
//     print(0) 
//   else:
//     print(1)


// for ii in range(int(input())):
//   x , k  = map(int ,input().split())
//   bruh(x,k)
#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int x, k;
        cin >> x >> k;
        vector<int> f2;
        while(x%2 == 0) {
            f2.push_back(2);
            x /= 2;
        }
        for(int i = 3 ; i*i <= x; i += 2) {
            while(x % i == 0) {
                x /= i;
                f2.push_back(i);
            }
        }
        if(x >= 3) f2.push_back(x);   
        if(f2.size() < k) cout << 0 << endl;
        else              cout << 1 << endl;
    }

    return 0;
}