#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int sum = 0;
        int x;
        for(int i = 0 ; i < s.size() ; i++) {
            x = s[i] - '0';
            if(x >= 0 && x <= 9) sum += x;
        }
        cout << sum << endl;
    }
    return 0;
}