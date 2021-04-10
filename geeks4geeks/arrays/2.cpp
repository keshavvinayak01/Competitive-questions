#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

long long thirdLargest(long long arr[], long long n) {
    if(n < 3) return -1;
    else {
        for(long long i = 0 ; i < 3; i++) {
            for(long long j = 0 ; j < n ; j++) {
                if(arr[j] > arr[j+1]) swap(arr[j+1], arr[j]);
            }
        }
    }
    return arr[n-3];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        long long arr[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        cout << thirdLargest(arr, n) << endl;
    }

    return 0;
}