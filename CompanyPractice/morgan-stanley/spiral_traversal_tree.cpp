#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        int arr[n][m];
        bool marked[n][m];
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                cin >> arr[i][j];
                marked[i][j] = false;
            }
        }
        int up, down, left, right;
        up = left = 0;
        down = n-1;
        right = m-1;
        int mark_count = 0;
        while(mark_count < n*m) {
            // Go right
            for(int i = left; i <= right; i++) {
                if(!marked[up][i])
                    cout << arr[up][i] << " ";
                marked[up][i] = true;
                mark_count++;
            }
            up++;
            // Go down
            for(int i = up; i <= down; i++) {
                if(!marked[i][right])
                    cout << arr[i][right] << " ";
                marked[i][right] = true;
                mark_count++;
            }
            right--;
            // Go left
            for(int i = right; i >= left; i--) {
                if(!marked[down][i])
                    cout << arr[down][i] << " ";
                marked[down][i] = true;
                mark_count++;
            }
            down--;            
            // Go up
            for(int i = down; i >= up; i--) {
                if(!marked[i][left])
                    cout << arr[i][left] << " ";
                marked[i][left] = true;
                mark_count++;
            }
            left++;
        }        
        cout << endl;
    }
    return 0;
}