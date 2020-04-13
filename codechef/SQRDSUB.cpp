#include<bits/stdc++.h>
typedef unsigned long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        int po2[n];
        for(int i = 0 ; i < n ; i++) {
            if(arr[i] % 4 == 0) po2[i] = 2;
            else if(arr[i] % 2 == 0) po2[i] = 1;
            else po2[i] = 0; 
        }
        // First count number of 1s and pairwise 1s(n(n+1)/2)
        // Next, For all powers of 4, everything ahead and before possible(n(n-1)).
        // subtract k(k+1)/2 - 1 where k is the number of 4 in array
        // Include 1 for only first 4.
        // Compress
    }

    return 0;
}