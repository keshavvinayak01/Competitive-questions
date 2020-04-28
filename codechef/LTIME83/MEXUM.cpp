#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 998244353
using namespace std;

lli getAns(vector<lli> piv) {
    if(piv.size() > 0) {
        for(int i = 0 ; i < piv.size(); i++) cout << piv[i] << " ";
        cout << endl;
    }
    if(piv.size() == 0) return 1;
    else {
        if(piv[0] > 1) return 1;
        else return piv[piv.size() - 1] + 1;
    }
}

lli getMaxSum(lli arr[], int curr, int n, vector<lli> piv) {
    if(curr >= n-1) {
        return getAns(piv);
    }
    vector<lli> newPiv(piv);
    newPiv.push_back(arr[curr]);
    return (getMaxSum(arr, curr + 1, n, piv) % MOD + getMaxSum(arr, curr + 1, n, newPiv) % MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        lli arr[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        sort(arr, arr + n);
        vector<lli> piv;
        cout << getMaxSum(arr, 0, n, piv) % 998244353 << endl;
    }

    return 0;
}