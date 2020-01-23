#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    lli a, b, ans;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        ans = 1;
        bool visited[100000000];

        for(int i = 2 ; i <= min(a, b); i++) {
            for(int j = i; j < max(a, b); j += i) {
                if(!visited[i])
                    if((a-1) % j == (b-1) % j) ans++;
                visited[i] = true;
            }
        }
        cout << ans << endl;
    }
    return 0;
}