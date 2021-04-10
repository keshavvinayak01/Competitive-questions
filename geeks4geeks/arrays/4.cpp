#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

long long minDist(long long arr[], long long n, long long x, long long y) {
    int ans = 100001, i = 0, start;
    while(i < n) {
        if(arr[i] == x) {
            start = i;
            while(arr[i] != y && i < n) {
                i++;
                if(arr[i] == x) {start = i;};
            }
            if(arr[i] == y)
                ans = min(ans, i - start);
        }
        if(arr[i] == y) {
            start = i;
            while(arr[i] != x && i < n) {
                i++;
                if(arr[i] == y) {start = i;}
            }
            if(arr[i] == x)
                ans = min(ans, i - start);
        }
        i++;
    }
    return ans == 100001 ? -1 : ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        long long n, x ,y;
        cin >> n;
        long long arr[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        cin >> x >> y;
        cout << minDist(arr, n, x, y) << endl;
    }

    return 0;
}