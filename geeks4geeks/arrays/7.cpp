#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

int max_path_sum(int arr1[], int arr2[], int n, int m) {
    int sum1 = 0, sum2 = 0, ans = 0;
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(i < n && arr1[i] < arr2[j]) sum1 += arr1[i++];
        if(j < n && arr1[i] > arr2[j]) sum2 += arr2[j++];
        if(arr1[i] == arr2[j]) {
            ans += arr1[i] + max(sum1, sum2);
            sum1 = sum2 = 0;
            i++; j++;
        }
    }
    while(i < n) sum1 += arr1[i++];
    while(j < m) sum2 += arr2[j++];
    ans += max(sum1, sum2);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for(int i = 0 ; i < n ; i++) cin >> arr1[i];
        for(int i = 0 ; i < m ; i++) cin >> arr2[i];
        cout << max_path_sum(arr1, arr2, n, m) << endl;
    }
    return 0;
}