#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ll a, n, k;
    cin >> a >> n >> k;

    for(int i = 0 ; i < k; i++) {
        cout << a % (n + 1) << " "; 
        a = a/(n + 1);
    }
    cout << endl;
    
    return 0;
}