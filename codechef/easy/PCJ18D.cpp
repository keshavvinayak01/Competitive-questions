#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;

bool isSatisfied(lli k, lli b, lli n) {
    int total_cookies = 0;
    int crumbs = 0;

    while(k > 0) {
        total_cookies += k;
        crumbs += k;
        k = crumbs / b;
        crumbs %= b;
    } 
    if(total_cookies >= n) return true;
    return false;
}

int getAns(lli start, lli end, lli b, lli n) {
    if(start == end) return start;
    if(start > end) return 0;

    lli mid = (start + end)/2;
    if(isSatisfied(mid, b, n)) {
        return getAns(start, mid, b, n);
    }
    else {
        return getAns(mid+1, end, b, n);
    }
}

int main() {
    lli t, n, b;
    cin >> t;
    while(t--) {
        cin >> n >> b;
        cout << getAns(1, n, b, n) << endl;
    }

    return 0;
}