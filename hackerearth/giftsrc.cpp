#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string curr_move;
        string s;
        cin >> s;
        int x = 0, y = 0;
        for(int i = 0 ; i < s.length(); i++) {
            curr_move = "";
            while((s[i] == s[i+1]) || 
                  (s[i] == 'R' && s[i+1] == 'L') ||
                  (s[i] == 'L' && s[i+1] == 'R')) {
                    if(curr_move == "") curr_move = s[i];
                    i++;
            }
            if(curr_move == "") curr_move = s[i];
            if(curr_move == "L") x--;
            if(curr_move == "R") x++;
            curr_move = "";
            while((s[i] == s[i+1]) || 
                  (s[i] == 'U' && s[i+1] == 'D') ||
                  (s[i] == 'D' && s[i+1] == 'U')) {
                    if(curr_move == "") curr_move = s[i];
                    i++;
            }
            if(curr_move == "") curr_move = s[i];
            if(curr_move == "D") y--;
            if(curr_move == "U") y++;
        }
        cout << x << " " << y << endl;
    }

    return 0;
}