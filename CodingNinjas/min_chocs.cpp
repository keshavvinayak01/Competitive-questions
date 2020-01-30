#include<bits/stdc++.h>
using namespace std;

int getMin(int *a, int n){
    int dp[n];
    dp[0] = 1;
    for(int i=1; i < n; i++){
        if(a[i] > a[i-1]){
            dp[i] = dp[i-1] + 1;
        }
        else if(a[i] <= a[i-1]){
            dp[i] = 1;
        }
    }
    for(int i = n-2; i >= 0; i--){
        if(a[i] > a[i+1] && dp[i] <= dp[i+1]){
            dp[i] = 1 + dp[i+1];
        }
    }
    int sum = 0;
    for(int i=0 ; i < n; i++) sum+= dp[i];
    return sum;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i < n; i++)
        cin >> a[i];
    cout << getMin(a, n) << endl;
    return 0;
}