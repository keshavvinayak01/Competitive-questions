#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

struct query {
    int x1, x2, y, count;
};

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n, q, count;
    cin >> t;
    while(t--) {
        cin >> n >> q;
        int arr[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        query queries[q];
        for(int i = 0 ; i < q ; i++) cin >> queries[i].x1 >> queries[i].x2 >> queries[i].y;
        for(int i = 0 ; i < q ; i++) {
            count = 0;  
            for(int j = queries[i].x1-1; j < queries[i].x2-1; j++) {
                if(queries[i].y >= min(arr[j], arr[j+1]) && 
                   queries[i].y <= max(arr[j], arr[j+1])) count++;
            }
            queries[i].count = count;
        }
        for(int i = 0 ; i < q; i++) cout << queries[i].count << endl;
    }

    return 0;
}