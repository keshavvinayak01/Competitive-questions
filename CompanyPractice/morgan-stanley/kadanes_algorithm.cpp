#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];

        int max_temp = 0, ans = INT_MIN;
        for(int i = 0 ; i < n ; i++) {
            max_temp += arr[i];
            
            if(max_temp > ans) ans = max_temp;
            if(max_temp < 0) max_temp = 0;

        }
        cout << ans << endl;
    }

    return 0;
}