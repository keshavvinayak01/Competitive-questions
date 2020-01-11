#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int arr[n][m];
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                cin >> arr[i][j];
        int ans = m*n;
        for(int i = 0 ; i < n-1; i++) {
            for(int j = 1; j < m-1; j++) {
                int rh = j+1, lh = j-1;
                int rv = i+1, lv = i-1;
                // cout << "Values : " << lh << " " << rh << " " << lv << " " << rv << endl;
                // cout << "Horizontal " << arr[i][rh] << " " << arr[i][lh] << endl;
                // cout << "vertical " << arr[rv][j] << " " << arr[lv][j] << endl;
                while((rh < m && lh >= 0) && (rv < n  && lh >= 0) && 
                    // (arr[i][rh] == arr[lv][j] && arr[rv][j] == arr[i][lh]) 
                    // // || 
                    // // (arr[i][rh] == arr[rv][j] && arr[lv][j] == arr[i][lh]) ||
                    (arr[i][rh] == arr[i][lh] && arr[rv][j] == arr[lv][j])
                ){
                    // cout << "Didn't run?\n";
                    ans++;
                    rh++;lh--;
                    rv++;lv--;
                }
            }
        }
        cout << ans << endl;
        
    }

    return 0;
}