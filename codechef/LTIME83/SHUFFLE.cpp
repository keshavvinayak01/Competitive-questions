#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

bool sortThis(pair<lli, lli> a, pair<lli, lli> b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli t;
    cin >> t;
    while(t--) {
        lli k, n;
        cin >> n >> k;
        pair<lli, lli> arr[n];
        for(int i = 0 ; i < n ; i++) {cin >> arr[i].first;arr[i].second = i;}
        sort(arr, arr + n, sortThis);
        bool ans = true;
        bool ans2;
        int temp;
        for(int i = 0 ; i < n ; i++) {
            if((arr[i].second - i) % k != 0) {
                // after
                ans2 = false;
                for(int j = i + 1; arr[j].first == arr[i].first; j++) {
                    if((arr[j].second - i) % k == 0) {
                        ans2 = true;
                        temp = arr[i].second;
                        arr[i].second = arr[j].second;
                        arr[j].second = temp;
                        break;       
                    }
                }
                if(ans2) continue;
                else {
                    ans = false;
                    break;
                }

            }
        }
        if(!ans) cout << "no\n";
        else     cout << "yes\n";
    }

    return 0;
}