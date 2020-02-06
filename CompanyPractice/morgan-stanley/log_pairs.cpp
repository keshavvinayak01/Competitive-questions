#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

bool satisfies(int a, int b) {
    if(a <= 1 || b <= 1) {
        return pow((float)a, (float)b) > pow((float)b, (float)a);
    }
    return log2((float)a)/log2((float)b) > (float)a / (float)b;
}


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n, m, ans, j, temp;
    cin >> t;
    while(t--) {
        cin >> n >> m;  
        int arr1[1001];
        int arr2[1001];
        for(int i = 1; i <= 1000; i++) {
            arr1[i] = arr2[i] = 0;
        }
        for(int i = 0 ; i < n ; i++) {
            cin >> temp;
            arr1[temp]++;
        };
        for(int i = 0 ; i < m ; i++) {
            cin >> temp;
            arr2[temp]++;
        }
        ans = 0;
        
        for(int i = 1 ; i <= 1000; i++) {
            if(arr1[i] > 0)
                for(int j = 1 ; j <= 1000; j++) {
                    if(arr2[j] > 0) {
                        if(satisfies(i, j)) ans += arr1[i] * arr2[j];
                    }
                }
        }
        cout << ans << endl;
    }

    return 0;
}