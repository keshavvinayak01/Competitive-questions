#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

lli won_fights(lli arr1[], lli arr2[], int n) {
    int ans = 0;
    int i = 0, j = 0;
    while(i < n && j < n) {
        if(arr1[i] > arr2[j]) {
            ans++;
            i++; j++;
        } 
        else {
            i++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        lli arr1[n], arr2[n];
        for(int i = 0 ; i < n ; i++) cin >> arr1[i];
        for(int i = 0 ; i < n ; i++) cin >> arr2[i];
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + n);
        cout << won_fights(arr1, arr2, n) << endl;
    }

    return 0;
}