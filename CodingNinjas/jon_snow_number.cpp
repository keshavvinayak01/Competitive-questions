#include<bits/stdc++.h>
using namespace std;

void print_max_and_min(vector<int> arr){
    int min = INT_MAX;
    int max = INT_MIN;
    for(int i = 1 ; i <= 1024; i++){
        if(i < min && arr[i] > 0) min = i;
        if(i > max && arr[i] > 0) max = i;
    }
    cout << max << " " << min << endl;
}

void print_dp(vector<int> dp){
    for(int i = 1 ; i <= 40 ; i++)
        cout << dp[i] << " " ;
    cout << endl;
}

void bad_solution(int n, int k, int x, int* arr){
    for(int i = 0 ; i < k; i++){
        sort(arr, arr+n);
        for(int j = 0; j < n; j = j+2){
            arr[j] = arr[j]^x;
        }
    }
    int min = INT_MAX;
    int max = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];

    }
    cout << max << " " << min << endl;
}

int main(){
    int n,k,x;
    cin >> n >> k >> x;
    int arr[n];
    // vector<int> dp(1025);
    for(int i = 0 ; i < n; i++) cin >> arr[i];
    bad_solution(n,k,x,arr);
    // for(int j = 0 ; j < n; j++){
    //     dp[arr[j]]++;
    // }
    // int count;
    // vector<int> temp_dp(1025);
    // for(int i = 0 ; i < k; i++){
    //     count = 0;
    //     for(int j = 1 ; j <= 1025; j++){
    //         if(dp[j] > 0){
    //             int t = dp[j];
    //             int new_i = j^x;
    //             if(t%2 == 0){
    //                 count += t/2;
    //                 temp_dp[j] = t/2;
    //                 temp_dp[new_i] += t/2;
    //             }
    //             else{
    //                 if(count%2 !=  0){
    //                     count += t/2 + 1;
    //                     temp_dp[j] += t/2 + 1;
    //                     temp_dp[new_i] += t/2;
    //                 }
    //                 else{
    //                     count += t/2 + 1;
    //                     temp_dp[j] += t/2;
    //                     temp_dp[new_i] += t/2 + 1;
    //                 }
    //             }
        
    //         }
    //     }
    //     print_dp(temp_dp);
    //     dp = temp_dp;
    //     fill(temp_dp.begin(), temp_dp.end(), 0);
    // }
    // print_max_and_min(dp);
    return 0;
}