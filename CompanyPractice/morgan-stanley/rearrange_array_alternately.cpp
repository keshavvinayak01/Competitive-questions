#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli t, n, max_e;
    cin >> t;
    while(t--) {
        cin >> n;
        lli* arr = new lli[n];
        for(lli i = 0 ; i < n ; i++) cin >> arr[i];
        max_e = arr[n-1] + 1;
        if(n%2 != 0) 
            arr[n-1] = (arr[n/2]) * max_e + arr[n-1];
        
        for(lli i = 0 ; i < n/2 ; i++) {
            lli x = 2*i + 1;
            arr[x] = (arr[i] % max_e) * max_e + arr[x];
            arr[x-1] = (arr[n-i-1] % max_e) * max_e + arr[x-1];
        }
        for(lli i = 0 ; i < n ; i++) {
            cout << arr[i]/max_e << " ";
        }
        cout << endl;
        delete[] arr;
    }
    return 0;
}