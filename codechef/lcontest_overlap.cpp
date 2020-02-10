#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

bool check_base(lli b, lli base) {
    if((b == base*11 + 7) || 
       (b == base*11 + 2) ||
       (b == base*11 + 1))
       return true;
    else return false;
}
lli get_ans(lli b, bool first) {
    lli base = (b)/11;
    lli ans = base*3;
    if(base <= 0) {
        if(b >= 7) ans += 3;
        else if(b == 1) ans += 1;
        else ans += 2;
    }
    else ans += 3;
    if(b >= base*11 + 7 && b < base*11 + 12) ans++;
    else {
        if(b >= base*11 + 2 && b < base*11 + 7) ans += 2;
        else if(b >= base*11 + 1 && b < base*11 + 7) ans += 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli t, a, b, c, d;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cin >> c >> d;
        lli ans1 = get_ans(b, true);
        lli ans2 = get_ans(d, false);
        lli full_ans = ans2 - ans1;
        if(check_base(b, b/11)) full_ans++;
        if(a > 2 && (check_base(b, b/11))) full_ans--;
        if(c < 2 && (check_base(d, d/11))) full_ans--; 
        if(full_ans < 0) full_ans = 0;
        cout << full_ans << endl;
    }

    return 0;
}