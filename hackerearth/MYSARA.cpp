#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

vector<int> get_binary(int x) {
    vector<int> ans(32, 0);
    int i = 31;
    // cout << x << " : " << endl;
    while(x > 0) {
        ans[i] = x%2;
        x /= 2;
        i--;
    }
    // for(int i = 0 ; i < 30 ; i++) cout << ans[i] << " ";
    // cout << endl;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    vector<int> bits1;
    vector<int> bits2;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ans = 1;
        int arr[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        bool ans_f = true;
        for(int i = 1 ; i < n; i++) {
            if(arr[i] < arr[i-1]) {
                ans_f = false;
                break;
            }
        }
        if(!ans_f) {
            cout << 0 << endl;
        }
        else {
            bits1 = get_binary(arr[0]);
            for(int i = 1 ; i < n ; i++) {
                bits2 = get_binary(arr[i]);
                for(int i = 0 ; i < 32; i++) {
                    if(bits1[i] == 1 && bits2[i] == 1) ans = ((ans % MOD) * 2)%MOD;
                }
                // cout << arr[i-1] << " " << arr[i] << " " << single_ans << endl;
                bits1 = bits2;
            }
            cout << ans << endl;
        }
        
    }

    return 0;
}