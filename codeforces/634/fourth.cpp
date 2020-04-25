#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, grid[9][9], n = 9;
    cin >> t;
    while(t--) {
        string s;
        for(int i = 0 ; i < n ; i++) {
            cin >> s;
            for(int j = 0 ; j < n ; j++)
                grid[i][j] = s[j] - '0';
        } 
        grid[0][0] = grid[0][1];
        grid[1][3] = grid[1][4];
        grid[2][6] = grid[2][7];
        grid[3][1] = grid[3][2];
        grid[4][4] = grid[4][5];
        grid[5][7] = grid[5][8];
        grid[6][2] = grid[6][3];
        grid[7][5] = grid[7][6];
        grid[8][8] = grid[8][7];
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) 
                cout << grid[i][j];
            cout << endl;
        } 
            
    }

    return 0;
}