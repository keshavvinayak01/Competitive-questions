#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll t1, t2, t3, t4;
        cin >> t1 >> t2 >> t3 >> t4;
        cout << float(t1)/float(t2 + t1) << endl;
    }

    return 0;
}