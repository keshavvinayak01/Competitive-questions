#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n;
    bool f;
    cin >> t;
    while(t--) {
        cin >> n;
        if(n/2 % 2 != 0) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            if(n == 4) {
                cout << "2 4 1 5\n";
            }
            else {
                int arr[n];
                for(int i = 1 ; i <= n/2; i++) {
                    arr[i-1] = i*2;
                }
                for(int i = n/2 ; i < (3*n)/4; i += 2) {
                    arr[i] = arr[i-n/2] - 1;
                    arr[i+1] = arr[i-n/2+1] - 1;
                }
                for(int i = (3*n)/4 ; i < n; i += 2) {
                    arr[i] = arr[i-n/2] + 1;
                    arr[i+1] = arr[i-n/2+1] + 1;
                }
                for(int i = 0 ; i < n ; i++) cout << arr[i] << " ";
                cout << endl;
            }
        }
    }

    return 0;
}