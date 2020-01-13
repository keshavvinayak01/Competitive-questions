#include<bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, ans = 1;
        cin >> n;
        int32_t arr[n];
        for(int i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        for(int i = 1 ; i < n ; i++) {
            if(arr[i] < arr[i-1]) ans++;
            else {
                arr[i] = arr[i-1];
            }
        }
        cout << ans << endl;
    }

    return 0;
}