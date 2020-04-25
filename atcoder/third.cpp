#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli n, temp;
    cin >> n;
    int arr[n + 1];
    memset(arr, 0, sizeof(arr));
    for(int i = 0 ; i < n-1 ; i++) {
        cin >> temp;
        arr[temp]++;
    }
    for(int i = 1 ; i <= n ; i++) cout << arr[i] << endl;
    return 0;
}