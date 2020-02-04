#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, higher, comp, low, high;
    cin >> t;
    while(t--) {
        
        cin >> n;
        int arr[n];
        for(int i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        
        sort(arr, arr + n);
        int ans = 0;
        for(int i = n-1; i >= 0 ; i--) {
            higher = arr[i];
            low = 0;
            high = i-1;
            while(low < high) {
                comp = arr[low] + arr[high];
                if(comp == higher) {
                    ans++;
                    low++;
                    high++;
                }
                if(comp > higher) high--;
                if (comp < higher) low++;
            }
        }
        if(ans == 0) cout << -1 << endl;
        else         cout << ans << endl;
    }

    return 0;
}