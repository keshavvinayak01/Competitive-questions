/* 
Calculate the Grundy Number for the given 'n' in the game.

The game starts with a number- ‘n’ and the player to move divides the number- ‘n’ with 2, 3 or 6 
and then takes the floor. If the integer becomes 0, it is removed. The last player to move wins. 
Which player wins the game?

*/

#include<bits/stdc++.h>
using namespace std;

int mex(int a, int b, int c) {
    int min_num = min(a, min(b, c));
    int max_num = max(a, max(b, c));
    int ans = min_num;

    if(min_num != 0) return 0;

    while(ans == a || ans == b || ans == c) ans++;
        
    return ans;
}

int grundy(int n) {
    if(n == 0) return 0;
    // Can only remove n/2, n/3, or n/6 stones
    
    return mex(grundy(n/2), grundy(n/3), grundy(n/6));
}

int main() {
    int n;
    cin >> n;
    cout << grundy(0) << endl;
    return 0;
}