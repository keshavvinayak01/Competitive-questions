#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli n, a, b;
    cin >> n;
    set<pair<lli, lli>> dislikes;
    lli ans = (n*(n-1))/2;
    for(int i = 0 ; i < 10 ; i++) {
        cin >> a;
        for(int i = 0 ; i < 9 ; i++) {
            cin >> b;
            dislikes.insert(make_pair(min(a, b), max(a, b)));
        }
    }
    cout << ans - dislikes.size() << endl;
    return 0;
}