#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int* dp = new int[101];

void clear_dp(){
    for(int i = 0 ; i<=100; i++) dp[i] = 0;
}

int ncr(int n, int k) {  
    int res = 1;  
    if ( k > n - k )  
        k = n - k;  
    for (int i = 0; i < k; ++i)  
    {  
        res *= (n - i);  
        res /= (i + 1);  
    }  
  
    return res;  
}  
  

int getMinSum(int* a, int n, int k){
    sort(a, a+n);
    int res = 0;
    for(int i = 0 ;  i < k; i++){
        res += a[i];
    }
    return res;
}

int get_first_k(int n, int minSum){
    int res = 1;
    int r;
    for(int i = 1 ; i <=n; i++){
        if(i <= minSum){
            r = min(dp[i], minSum/i);
            res *= ncr(dp[i], r);
            minSum -= r*i;
        }
        else{
            break;
        }
    }
    return res;
}

int main(){
    int t;
    cin >>t;
    int answers[t];
    int n, k;
    int temp;
    int x;
    for(int it = 0; it < t; it++){
        clear_dp();
        cin >> n >> k;
        int a[n];
        
        for(int i = 0; i < n; i++){
            cin >> a[i];
            dp[a[i]]++;
        }
        int minSum = getMinSum(a, n, k);
        answers[it] =  get_first_k(n, minSum);
    }
    for(int i =  0 ; i < t ; i++){
        cout << answers[i] << endl;
    }
    return 0;   
}