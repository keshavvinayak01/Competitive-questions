#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        if(n == 1) {
            cout << "YES\n";
            continue;
        }
        
        int current;
        string ans = "YES";
        
        for(int i = 0 ; i< n-2; i++) {
            if(ans == "NO") break;
            current = arr[i];
            for(int j = i+2 ; j < n ; j++) {
                if(current > arr[j]) {
                    ans = "NO";
                    break;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}