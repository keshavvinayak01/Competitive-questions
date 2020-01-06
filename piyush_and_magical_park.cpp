#include<bits/stdc++.h>
using namespace std;

int maxStrength(char** grid, int n, int m, int s) {
    int currStr = s;
    bool breakLine;
    for(int i = 0 ; i < n ; i++) {
        breakLine = false;
        for(int j = 0 ; j < m ; j++) {
            if(grid[i][j] == '.') currStr -= 2;
            else if(grid[i][j] == '*') currStr += 5;
            else if(grid[i][j] == '#') breakLine = true;
            if(j != m-1 && !breakLine) currStr -= 1;
            if(breakLine) break;
        }
    }
    return currStr;
}

int main() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    char** grid = new char*[n];

    for(int i = 0 ; i < n ; i++) {
        grid[i] = new char[m];
        for(int j = 0 ; j < m ; j++) {
            cin >> grid[i][j];
        }
    }
    int ans = maxStrength(grid, n, m, s);
    if(ans >= k) {
        cout << "Yes\n" << ans << endl;
    }
    else {
        cout << "No\n";
    }
    return 0;
}