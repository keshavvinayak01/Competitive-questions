#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
#define PI 3.14159265
using namespace std;

int check_right(vector<int> pos_x, vector<int> neg_x, int y) {
    int ans = 0;
    lli a, b, c;
    for(int i = 0 ; i < pos_x.size() ; i++) 
        for(int j = 0 ; j < neg_x.size(); j++) {
            a = y * y + pos_x[i] * pos_x[i];
            b = y * y + neg_x[j] * neg_x[j];
            c = (pos_x[i] + neg_x[j]) * (pos_x[i] + neg_x[j]);
            if(a + b == c) ans++;
        }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int ans;
    bool x_zero, y_zero;
    int t, temp;
    vector<int> pos_x, neg_x;
    vector<int> pos_y, neg_y;
    cin >> t;
    while(t--) {
        pos_x.clear(); neg_x.clear();
        pos_y.clear(); neg_y.clear();
        x_zero = false;
        y_zero = false;
        ans = 0;
        int n, m;
        cin >> n >> m;
        for(int i = 0 ; i < n ; i++) {
            cin >> temp;
            if(temp == 0) x_zero = true;
            else if(temp < 0) neg_x.push_back(abs(temp));
            else         pos_x.push_back(temp);
        }
        for(int i = 0 ; i < m ; i++) {
            cin >> temp;
            if(temp == 0) y_zero = true;
            else if(temp < 0) neg_y.push_back(abs(temp));
            else         pos_y.push_back(temp);
        }
        
        if(x_zero && !y_zero) ans += m*(n - 1);
        else if(y_zero && !x_zero) ans += (m-1)*n;
        else if(x_zero && y_zero) {
            ans += 2*(m-1)*(n-1);
        }
        /* *****************Y axis is top vertex *********************/
        // Taking Y from positive axis
        for(int i = 0 ; i < pos_y.size() ; i++) {
            ans += check_right(pos_x, neg_x, pos_y[i]);
        }
        // Taking Y from negative axis
        for(int i = 0 ; i < neg_y.size() ; i++) {
            ans += check_right(pos_x, neg_x, neg_y[i]);
        }
        /* ***********************************************************/

        /* *****************X axis is top vertex *********************/
        // Taking X from positive axis
        for(int i = 0 ; i < pos_x.size() ; i++) {
            ans += check_right(pos_y, neg_y, pos_x[i]);
        }
        // Taking X from negative axis
        for(int i = 0 ; i < neg_x.size() ; i++) {
            ans += check_right(pos_y, neg_y, neg_x[i]);
        }
        /* ***********************************************************/
        cout << ans << endl;
    }

    return 0;
}