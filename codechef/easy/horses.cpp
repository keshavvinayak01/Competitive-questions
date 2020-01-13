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
        sort(arr, arr + n);
        int minDiff = INT_MAX;
        for(int i = 0 ; i < n-1; i++) {
            minDiff = min(minDiff, arr[i+1] - arr[i]);
        }
        cout << minDiff << endl;
    }
    return 0;
}   