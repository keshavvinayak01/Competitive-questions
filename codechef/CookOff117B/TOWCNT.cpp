#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

// Do in terms of slope ya idiot

struct obs {
    lli t, x, y;
};
bool sortX(obs a, obs b) {
    return a.x < b.x;
}
double calcSlope(obs a, obs b) {
    if(a.y == b.y) return 0;
    else 
        return(double(b.y - a.y) / double(b.x - a.x));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli t, h, n, tt, tx, ty, l, r; 
    int slope_up, slope_down, temp_slope;
    cin >> t;
    while(t--) {
        cin >> h >> n;
        obs arr[n];
        for(int i = 0 ; i < n ; i++) {
            cin >> tt >> tx >> ty;
            arr[i].t = tt; arr[i].x = tx; arr[i].y = ty;
        }
        sort(arr, arr + n, sortX);
        lli ans[n];
        memset(ans, 0, sizeof(ans));
        bool is_possible[n][n];
        memset(is_possible, true, sizeof(is_possible));
        for(int i = 0 ; i < n ; i++) {
            slope_up = INT_MAX; slope_down = INT_MIN;
            if(i != n-1) {
                r = i + 1;
                while(r < n) {
                    temp_slope = calcSlope(arr[i], arr[r]);
                    if(arr[r].t == 0) {
                        if(temp_slope >= slope_down && temp_slope <= slope_up) {
                            ans[i]++; ans[r]++;
                            slope_down = max(temp_slope, slope_down);
                        }
                    }
                    else {
                        if(temp_slope >= slope_down && temp_slope <= slope_up) {
                            ans[i]++; ans[r]++;
                            slope_up = min(temp_slope, slope_up);
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