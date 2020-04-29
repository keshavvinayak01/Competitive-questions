#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

void rotateArr(int arr[], int d, int n) {
    int arr2[n];
    int temp_i;
    for(int i = 0 ; i < n ; i++) {
        temp_i = (i - d) % n;
        temp_i = temp_i < 0 ? temp_i + n : temp_i;
        arr2[temp_i] = arr[i];
    }
    for(int i = 0 ; i < n ; i++) arr[i] = arr2[i];
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, d;
        cin >> n >> d;
        int arr[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        rotateArr(arr, d, n);
    }

    return 0;
}