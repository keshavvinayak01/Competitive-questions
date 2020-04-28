#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

bool sortThis(pair<int, int> a, pair<int, int> b) {
    if(b.second == a.second) {
        return a.first < b.first;
    }
    else return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, s, r;
        cin >> n >> s;
        r = 100 - s;
        pair<int, int> cost_player[n];
        for(int i = 0 ; i < n ; i++) cin >> cost_player[i].first;
        for(int i = 0 ; i < n ; i++) cin >> cost_player[i].second;
        int ans = false;
        for(int i = 0 ; i < n ; i++) {
            if(ans) break;
            for(int j = 0 ; j < n ; j++) {
                if(cost_player[i].second == 1 & cost_player[j].second == 0) {
                    if(cost_player[i].first + cost_player[j].first <= r) {
                        ans = true;
                        cout << "yes\n";
                        break;
                    }
                }
            }
        }
        if(!ans) cout << "no\n";
    }

    return 0;
}