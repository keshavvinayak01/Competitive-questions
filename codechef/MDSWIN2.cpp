#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 998244353
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli t, n, q, l, r, size;
    lli temp;
    cin >> t;
    while(t--) {
        cin >> n >> q;
        lli arr[n];
        for(int i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        while(q--) {
            cin >> l >> r;
            size = r - l + 1;
            vector<int> distinct;
            lli dist_count = 0, ans = 0;
            int* counts = new int[size];
            for(int i = l-1; i < r-1; i++) {
                if(counts[arr[i] % size] == 0){
                    distinct.push_back(arr[i]%size);
                    dist_count++;
                } 
                counts[arr[i] % size]++;
            }
            if(dist_count%2 == 0) {
                cout << 0 << endl;
            }   
            else {
                for(int i = 0 ; i < distinct.size(); i++) {
                    if(counts[distinct[i]] == 1) ans += 1;
                    
                }
            }
        }
    }

    return 0;
}