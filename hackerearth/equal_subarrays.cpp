#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli n, k;
    cin >> n >> k;
    lli arr[n];
    for(int i = 0 ; i < n ; i++) cin >> arr[i];

    lli curr_max, max_ans = 0, temp_ans;
    int i = 0, l, j, cost;

    while(i < n - max_ans) {
        curr_max = arr[i];
        j = i;
        while(j < n) {
            curr_max = max(curr_max, arr[j]);
            cost = 0;
            temp_ans = 0;
            l = i;
            while(l <= j && cost <= k) {
                cost += curr_max - arr[l];
                if(cost <= k) temp_ans++;
                l++; 
            }
            max_ans = max(max_ans, temp_ans);
            if(cost > k) break;
            
            if(j == n-1) {
                cout << max_ans << endl;
                return 0;
            }
        }   
        i++;
    }
    cout << max_ans << endl;
        
    return 0;
}