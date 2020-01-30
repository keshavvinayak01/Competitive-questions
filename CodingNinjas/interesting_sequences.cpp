#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll getCost(ll x, ll* a, ll n, ll k, ll i){
    ll increasing = 0, decreasing = 0;
    for(ll i=0; i < n; i++){
        if(a[i] > x){
            decreasing += a[i] - x;
        }
        else if(a[i] < x){
            increasing += x - a[i];
        }
    }
    ll cost = (decreasing)*k + (increasing - decreasing)*i;
    if(cost < 0) return INT_MAX;
    return cost;
}

int main(){
    ll n,k,cost_2;
    cin >> n >> k >> cost_2;
    ll a[n];
    for(ll i=0; i < n; i++){
        cin >> a[i];
    }
    ll start = INT_MAX, end = INT_MIN;
    for(ll i=0; i < n; i++){
        if(a[i] > end) end = a[i];
        if(a[i] < start) start = a[i];
    }
    ll cost = INT_MAX;
    for(ll i=start ; i <= end; i++){
        cost = min(cost, getCost(i, a, n, k, cost_2));
    }
    cout << cost;
    return 0;
}