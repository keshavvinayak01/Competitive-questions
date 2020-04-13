#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

bool reverseSort(int a, int b) {return a > b;}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli t, ans, n;
    cin >> t;
    while(t--) {
        cin >> n;
        lli arr[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        sort(arr, arr + n, reverseSort);
        ans = 0;
        for(int i = 0 ; i < n ; i++) ans = (ans % MOD + (max((lli)0, arr[i] - i))%MOD)%MOD;
        cout << ans << endl;
    }

    return 0;
}