#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;
long long arr[10000000];


long long findNumberOfTriangles(long long n) {
    sort(arr, arr + n);
    long long a, b, ans = 0;
    for(long long i = n -1 ; i >= 2 ; i--) {
        b = i-1;
        a = 0;
        while(a < b) {
            if(arr[a] + arr[b] > arr[i]) {
                ans += b - a;
                b--;
            }
            else 
                a++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    long long t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        for(long long i = 0 ; i < n ; i++) cin >> arr[i];
        cout << findNumberOfTriangles(n) << endl;
    }

    return 0;
}