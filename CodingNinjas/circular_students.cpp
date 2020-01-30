#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int i, p;
        cin >> i >> p;
        int ans = (i + p + 1)%12 - 1;
        if(ans == -1)
            cout << 11;
        else
            cout << ans << endl;
    }

    return 0;
}