#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int s, w1, w2, w3;
        cin >> s >> w1 >> w2 >> w3;
        if(s >= w1 + w2 + w3) {
            cout << 1 << endl;
        }
        else if(s >= w1 + w2 || s >= w3 + w2) {
            cout << 2 << endl;
        }
        else cout << 3 << endl;
    }

    return 0;
}