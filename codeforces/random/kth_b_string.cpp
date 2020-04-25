#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, position[2];
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int mid, start = 0, end = k;
        while(start != end) {
            mid = (start + end)/2;
            if(mid*(mid-1) >= 2*k) 
                end = mid - 1;
            else 
                start = mid + 1;
        }
        position[0] = start*(start+1) == 2*k ? start - 1: start;
        position[1] = start*(start+1) == 2*k ? start: k - (start*(start+1))/2 + 2;
        cout << start << " " << position[0] << " " << position[1] << endl;
        for(int i = n ; i >= 1 ; i--) {
            if(i == position[0] || i == position[1]) cout << "b";
            else cout << "a";
        }
        cout << endl;
    }

    return 0;
}