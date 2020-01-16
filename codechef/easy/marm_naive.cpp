#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    ll n, k;
    while(t--){
        cin >> n >> k;
        ll arr[n], a, b;
        for(int i = 0 ;i < n; i++) cin >> arr[i];
        // The pattern repeats after 3 iterations.
        // First calculate how many iterations actually required.
        for(ll j = 0; j < k; j++){
            a = arr[j%n];
            b = arr[n - j%n - 1];
            arr[j%n] = a^b;
        }
        for(int i = 0 ; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}