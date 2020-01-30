#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i=0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    ll minDif = a[n-1] - a[0];

    ll big = a[n-1] - k;
    ll small = a[0] + k;
    if(small > big) swap(small, big);
    for(int i=1; i < n-1; i++){
        ll subt = a[i] - k;
        ll add = a[i] + k;
        if(subt >= small || add <= big) continue;
        if(big - subt <= add - small) small=subt;
        else big=add;
    }
    cout << min(minDif, big - small) << endl;
    return 0;
}