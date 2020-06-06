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
        int minc = 1000000, curr_count, maxc = 1, j;
        for(int i = 0 ; i < n ; i++) {
            curr_count = 1;
            for(j = i+1; j < n ; j++) {
                if(arr[j] - arr[j-1] <= 2) curr_count++;
                else break;
            }
            i = j-1;
            minc = min(minc, curr_count);
            maxc = max(maxc, curr_count);
        }
        cout << minc << " " << maxc << endl;
    }

    return 0;
}