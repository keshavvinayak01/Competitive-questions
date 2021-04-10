#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

int maxLen(int arr[], int n) {
    unordered_map<int, int> hmap;
    int ans = INT_MIN, currSum = 0;
    for(int i = 0 ; i < n ; i++) {
        currSum += arr[i];
        if(currSum == 0) ans = max(ans, i + 1);
        if(hmap[currSum]) {
            ans = max(ans, i - hmap[currSum] + 1);
        }
        else {
            hmap[currSum] = i + 1;
        } 
    }
    return max(ans, 0);
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
        cout << maxLen(arr, n) << endl;
    }

    return 0;
}