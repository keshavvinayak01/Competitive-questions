#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

// Do in terms of slope ya idiot

struct obs {
    lli t, x, y;
};

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli t, h, n, tt, tx, ty, l, r, up_max, down_max;
    cin >> t;
    while(t--) {
        cin >> h >> n;
        obs arr[n];
        for(int i = 0 ; i < n ; i++) {
            cin >> tt >> tx >> ty;
            arr[i].t = tt; arr[i].x = tx; arr[i].y = ty;
        }
        lli ans[n];
        memset(ans, 0, sizeof(ans));
        bool is_possible[n][n];
        memset(is_possible, true, sizeof(is_possible));
        for(int i = 0 ; i < n ; i++) {
            up_max = INT_MAX; down_max = 0;
            if(i != n-1) {
                r = i + 1;
                while(r < n) {
                    if(arr[r].t == 0) {
                        if(arr[r].y >= down_max && down_max < up_max) {
                            ans[i]++; ans[r]++;
                            down_max = max(arr[r].y, down_max);
                        }
                    }
                    else {
                        if(arr[r].y <= up_max && up_max > down_max) {
                            ans[i]++; ans[r]++;
                            up_max = min(arr[r].y, up_max);
                        }
                    }
                    r++;
                }
            }
        }
        for(int i = 0 ; i < n ; i++) cout << ans[i] << " " ;
        cout << endl;
    }

    return 0;
}