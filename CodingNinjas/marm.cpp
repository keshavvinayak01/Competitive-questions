#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ll t;
    cin >> t;
    ll n, k;
    while(t--){
        cin >> n >> k;
        ll arr[n], a, b;
        for(ll i = 0 ;i < n; i++) cin >> arr[i];
        for(ll j = 0; j < k; j++){
            a = arr[j%n];
            b = arr[n - j%n - 1];
            arr[j%n] = a^b;
        }
        for(ll i = 0 ; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }

    return 0;
}