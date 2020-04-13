#include<bits/stdc++.h>
typedef long long int lli;
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
        int i = 0 ;
        bool ans = true;
        while(i < n && ans) {
            if(arr[i] == 1) {
                for(int j = i+1; j < i+6 && j < n ; j++) {
                    if(arr[j] == 1) {
                        ans = false;
                        break;
                    }
                }
                i += 6;
            }
            else i += 1;
        }
        if(!ans) cout << "NO\n";
        else     cout << "YES\n";
    }

    return 0;
}