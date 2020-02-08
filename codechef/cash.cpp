#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

// int get_left_coins(int arr[], int n, int c, int k) {
//     // Minimum I need to add ahead
//     int req_a = 0;
//     for(int i = c + 1; i < n ; i++) {
//         req_a = ceil(float(arr[i])/float(k))*k - arr[i];
//     }
//     // >= amount I can extract from before
//     int can_extract = 0;
//     int i = 0;
//     while(can_extract <= req_a && i < n) {
//         for(int i = 0 ; i <= c ; i++) {
//             if(arr[i]%k == 0 && arr[i] != 0) {
//                 can_extract += k;
//                 arr[i] -= k;   
//             }
//             else{
//                 arr[i] -= arr[i]%k;
//                 can_extract += arr[i]%k;
//             }
//         }
//         i++;
//         if(can_extract == req_a) break;
//     }
//     return can_extract - req_a >= 0 ? can_extract - req_a : INT_MAX;
// }

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n, k, ans;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        int arr[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        // ans = INT_MAX;
        // for(int i = 1 ; i < n ; i++) {
        //     ans = min(ans, get_left_coins(arr, n, i, k));
        // }
        // cout << ans << endl;
        lli can_remove = 0;
        for(int i = 0 ; i < n-1 ; i++) can_remove += arr[i];
        
        //  case 1 : previous all zeros
        if(can_remove == 0) {
            cout << arr[n-1] % k << endl;
            continue;
        }
        
        //  case 2 : arr[n-1] + can_remove <= nearest multiple
        lli ceil_val = ceil(float(arr[n-1])/float(k))*k;
        if(can_remove + arr[n-1] < ceil_val) {
            cout << can_remove + arr[n-1] % k << endl;
        }
        // Case 3 : Add as much to arr[n-1] as you can
        else {
            // if(can_remove < arr[n-1])
            lli mul = abs(can_remove + arr[n-1])/k;
            cout << can_remove - abs(mul*k - arr[n-1]) << endl;
        }
    }

    return 0;
}