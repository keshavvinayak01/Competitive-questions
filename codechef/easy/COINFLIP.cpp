#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int g;
        cin >> g;
        while(g--) {
            int n, i, q;
            cin >> i >> n >> q;
            if(n%2 == 0) cout << n/2 << endl;
            else {
                if(i == q) cout << (n-1)/2 << endl;
                else cout << (n+1)/2 << endl;
            }
        }
    }
    return 0;
}