#include<bits/stdc++.h>
#define MOD 1000000007
typedef long long int lli;
using namespace std;
 
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, except = -1;
        cin >> n;
        lli arr[n+2];
        for(int i = 0 ; i < n+2 ; i++) cin >> arr[i];
        sort(arr, arr + n + 2, less_equal<lli>());
        lli fullSum = 0;
        for(int i = 0; i < n+1; i++) fullSum += arr[i];
 
        // Check if any random element can be subtracted to obtain the actual sum
        for(int i = 0 ; i < n+1; i++) {
            if(fullSum - arr[i] == arr[n+1]) {
                except = i;
                break;
            }
        }
        if(except < 0){
            cout << -1 << endl;
        }
        else {
            for(int i = 0 ; i < n+1; i++) {
                if(i != except) cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}