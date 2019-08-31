#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int countBST(int n){
    int* output = new int[n];
    output[0] = 1;
    output[1] = 1;
    for(int i = 2 ; i <= n; i++){
        int ans = 0;
        for(int k = 1 ; k <= i; k++){
            ans += output[k-1]*output[i-k];
        output[i] = ans;
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