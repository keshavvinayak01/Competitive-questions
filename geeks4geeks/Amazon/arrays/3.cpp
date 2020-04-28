#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

void largestAndSecondLargest(int n, int arr[]) {
    int max1 = INT_MIN, max2 = -1;
    for(int i = 0 ; i < n ; i++) max1 = max(arr[i], max1);
    for(int i = 0 ; i < n ; i++) if(arr[i] != max1) max2 = max(max2, arr[i]);
    cout << max1 << " " << max2 << endl;    
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        largestAndSecondLargest(n, arr);
    }

    return 0;
}