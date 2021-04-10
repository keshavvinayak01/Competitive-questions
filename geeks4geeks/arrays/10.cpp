#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, max_e = -1, max_pos;
        cin >> n;
        vector<int> arr(n);

        for(int i = 0 ; i < n ; i++) cin >> arr[i];

        int arr_sum = 0, prev_sum = 0, next_sum, max_sum;
        for(int i = 0 ; i < n ; i++) arr_sum += arr[i];
        for(int i = 0 ; i < n ; i++) prev_sum += i*arr[i];
        max_sum = prev_sum;
        cout << arr_sum << " " << prev_sum << endl;
        for(int i = 0 ; i < n ; i++) {
            next_sum = prev_sum + (n)*arr[i] - arr_sum;
            prev_sum = next_sum;
            max_sum = max(next_sum, max_sum);
        }
        cout << max_sum << endl;
    }

    return 0;
}