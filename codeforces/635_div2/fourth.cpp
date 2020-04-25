#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

lli calcResult(lli a, lli b, lli c) {
    return abs((a - b) * (a - b)) + abs((a - c) * (a - c)) + abs((b - c) * (b - c));
}

lli getAns(vector<lli> a, vector<lli> b, vector<lli> c) {
    lli ans = LLONG_MAX;
    for(lli y : a) {
        auto x = lower_bound(b.begin(), b.end(), y);
        auto z = upper_bound(c.begin(), c.end(), y);
        if(x == b.end() || z == c.begin()) continue;
        z--;
        ans = min(ans, calcResult(*x, y, *z));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli t, nr, ng, nb, ans1, ans2, ans3, ans4, ans5, ans6;
    cin >> t;
    while(t--) {
        cin >> nr >> ng >> nb;
        vector<lli> arr_r(nr), arr_g(ng), arr_b(nb);
        for(int i = 0 ; i < nr ; i++) cin >> arr_r[i];
        for(int i = 0 ; i < ng ; i++) cin >> arr_g[i];
        for(int i = 0 ; i < nb ; i++) cin >> arr_b[i];
        sort(arr_r.begin(), arr_r.end());
        sort(arr_g.begin(), arr_g.end());
        sort(arr_b.begin(), arr_b.end());
        ans1 = getAns(arr_r, arr_g, arr_b);
        ans2 = getAns(arr_b, arr_g, arr_r);
        ans3 = getAns(arr_r, arr_b, arr_g);
        ans4 = getAns(arr_g, arr_b, arr_r);
        ans5 = getAns(arr_b, arr_r, arr_g);
        ans6 = getAns(arr_g, arr_r, arr_b);
        cout << min(ans1, min(ans2, min(ans3, min(ans4, min(ans5, ans6))))) << endl;
    }
    return 0;
}