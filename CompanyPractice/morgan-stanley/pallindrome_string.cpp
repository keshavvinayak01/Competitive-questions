#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, x;
    bool ans;
    string n;
    cin >> t;
    while(t--) {
        cin >> x;
        cin >> n;
        ans = true;
        if(n.size() %2 == 0) {
            int a = n.size()/2;
            int b = a - 1;
            while(a < n.size() && b >= 0) {
                if(n[a] == n[b]) {
                    a++; b--;
                }
                else {
                    ans = false;
                    break;
                };
            
            }
        }
        else {
            int a = n.size()/2;
            int b = a;
            while(a < n.size() && b >= 0) {
                if(n[a] == n[b]) {
                    a++; b--;
                }
                else {
                    ans = false;
                    break;
                };
            }
        }
        if(ans) cout << "Yes\n";
        else cout << "No\n";   
    }

    return 0;
}