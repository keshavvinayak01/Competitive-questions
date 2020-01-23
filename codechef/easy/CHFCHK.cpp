#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        sort(arr, arr + n);
        cout << arr[0] << endl;
    }
    return 0;
}