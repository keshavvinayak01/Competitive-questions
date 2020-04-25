#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, temp, first_val;
        cin >> n;
        int arr[n + 1], counts[n], rs[n];
        for(int i = 0 ; i < n ; i++) {
            cin >> temp;
            if(i == 0) first_val = temp;
            arr[temp] = i;
            counts[i] = 1;
            rs[i] = i;
        }
        for(int i = 1 ; i <= n ; i++) {
            if(i == 1) {
                
            }
        }
    }

    return 0;
}