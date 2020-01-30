#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
ll countBST(int n){
    ll* output = new ll[n + 1];
    output[0] = 1;
    output[1] = 1;
    for(int i = 2 ; i <= n; i++){
        ll ans = 0;
        for(int k = 1 ; k <= i; k++){
            ans += ((output[k-1]%MOD)*(output[i-k]%MOD))%MOD;
        output[i] = ans%MOD;
        }
    }
    
    return output[n];
}

int main(){
    int n ;
    cin >> n;
    cout << countBST(n) << endl;
    return 0;
}