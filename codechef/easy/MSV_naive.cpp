#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    lli t, n;
    cin >> t;
    int max_count, curr_count;
    while(t--) {
        cin >> n;
        max_count = INT_MIN;
        lli arr[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];

        for(int i = n-1; i > 0 ; i--) {
            
            curr_count = 0;
            
            for(int j = i-1; j >= 0 ; j--) {
                if(arr[j] % arr[i] == 0) curr_count++;
            }
            max_count = max(max_count, curr_count);
        }
        cout << max_count << endl;
    }
    return 0;
}