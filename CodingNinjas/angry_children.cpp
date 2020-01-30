#include<bits/stdc++.h>
using namespace std;

int* main_dp = new int[1000000];

int calc_unfair(int* dp, int start, int end){
    int res = 0;
    for(int i = start ; i < end ; i++)
        for(int j = i+1 ; j < end ; j++)
            res += abs(dp[i] - dp[j]);
    return res;
}

// int get_min_unfair(int* a, int k, int cur, int n, vector<int> dp, int max_k, int sum_a){
//     if(k == 0 || cur >= n){
//         if(dp.size() == max_k ){
//             int ans = calc_unfair(dp, max_k) ;
//             main_dp[sum_a] = ans;
//             return ans;
//         }
//         return INT_MAX;
//     }
//     if(main_dp[sum_a] > 0) {
//         return main_dp[sum_a];
//     };
//     int excl = get_min_unfair(a, k, cur + 1, n, dp, max_k, sum_a);
//     dp.push_back(a[cur]);
//     int incl = get_min_unfair(a, k-1, cur + 1, n, dp, max_k, sum_a + a[cur]);
//     return min(excl, incl);
// }

int main(){
    int n, k;
    cin >> n;
    cin >> k;
    int a[n];

    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    // vector<int> dp;
    // cout << get_min_unfair(a, k, 0, n, dp, k, 0) << endl;
    int min_count = INT_MAX;
    sort(a, a+n);
    for(int i = 0; i < n-k ; i++ ){
        min_count = min(min_count, calc_unfair(a, i, i+k));
    }
    cout << min_count << endl;
    return 0;
}