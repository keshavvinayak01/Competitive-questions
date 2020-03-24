#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int max_s;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int* weights = new int[n];
        max_s = INT_MIN;
        for(int i = 0 ; i < n ; i++) cin >> weights[i];
        for(int i = 0 ; i < n ; i++) max_s = max(weights[i], max_s);
        int longest_satis = INT_MIN;
        int curr_satis = 0;
        for(int i = 0 ; i < 2*n-1 ; i++) {
            if(weights[i%n] < max_s) curr_satis++;
            else {
                longest_satis = max(curr_satis, longest_satis);
                curr_satis = 0;
            }
        }
        longest_satis = max(curr_satis, longest_satis);
        if(longest_satis < n/2) cout << 0 << endl;
        else cout << longest_satis - n/2 + 1 << endl;
        delete[] weights;
    }

    return 0;
}