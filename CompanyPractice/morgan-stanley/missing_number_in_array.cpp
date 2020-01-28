#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, a;
        cin >> n;
        int arr[n+1];
        for(int i = 1 ; i <= n; i++) arr[i] = -1;
        for(int i = 0 ; i < n -1; i++) {
            cin >> a;
            arr[a] = 1;
        }
        for(int i = 1 ; i <= n ; i++) {
            if(arr[i] != 1) cout << i << endl;
        }
    }

    return 0;
}