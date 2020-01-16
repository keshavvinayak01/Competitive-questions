#include<bits/stdc++.h>
typedef long long int ill;
using namespace std;

ill getNumberOddInteger(ill rows[], ill cols[], ill n, ill m) {
    ill even_rows = n;
    ill odd_rows = 0;
    // for rows
    for(ill i = 1 ; i <= n ; i++) {
        if(rows[i] > 0) {
            if(rows[i]%2 == 0) continue;
            else {
                even_rows -= 1;
                odd_rows += 1;
            }
        }
    }
    // for cols
    ill no_odd = 0;
    for(ill i = 1 ; i <= m ; i++) {
        if(cols[i] > 0) {
            if(cols[i]%2 == 0) no_odd += (n - even_rows);
            else no_odd += (n - odd_rows);
        }
        if(cols[i] == 0) {
            no_odd += odd_rows;
        }
    }
    return no_odd;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ill t;
    cin >> t;
    ill n, m, q, a, b;
    while(t--) {
        cin >> n >> m >> q;
        ill cols[m + 1];
        ill rows[n + 1];
        for(ill i = 0 ; i <= n ; i++) {
            rows[i] = 0;
        }
        for(ill i = 0 ; i <= m ; i++) {
            cols[i] = 0;
        }

        for(ill i = 0 ; i < q ; i++) {
            cin >> a >> b;
            rows[a]++;
            cols[b]++;
        }
        cout << getNumberOddInteger(rows, cols, n, m) << endl;
    }


    return 0;
}