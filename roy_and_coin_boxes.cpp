#include<bits/stdc++.h>
using namespace std;
int dp[1000001];

int main(){
    int n, m;
    cin >> n;
    cin >> m;
    int start_times[n+1], end_times[n+1];
    for(int i = 0 ; i <=n ; i++){
        start_times[i] = end_times[i] = 0;
    }
    for(int i = 0 ; i <= n; i++){
        dp[i] = 0;
    }

    for(int i = 0 ; i < m; i++){
        int start_time, end_time;
        cin >> start_time >> end_time;
        start_times[start_time]++;
        end_times[end_time]++;
    }
    dp[1] = start_times[1];
    for(int i = 2; i <= n; i++) {
        dp[i] = start_times[i] - end_times[i-1] + dp[i-1];
    }
    int freq[n+1];
    for(int i = 1; i <= n; i++){
        freq[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        freq[dp[i]] += 1;
    }
    int res[n+1];
    res[n] = freq[n];
    for(int i = n-1 ; i >=1; i-- ){
        res[i] = freq[i] + res[i+1];
    }
    int q;
    cin >> q;
    int queries[q];
    for(int i = 0 ; i < q; i++){
        cin >> queries[i];
    }
    for(int i =  0 ; i < q; i++){
        cout << res[queries[i]] << endl;
    }
    return 0;
}