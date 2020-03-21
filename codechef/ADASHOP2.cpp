#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

bool completed_board(bool completed[8]) {
    for(int i = 0 ; i < 8 ; i++) {
        if(!completed[i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, curr_r, curr_c, init_r, init_c, begin_r, begin_c, end_r, end_c, mid_p;
    cin >> t;
    while(t--) {
        cin >> init_r >> init_c;
        bool completed[8];
        vector<pair<int, int>> moves;
        curr_r = init_r; curr_c = init_c;
        while(curr_c <= 8) {
            mid_p = (curr_r + curr_c)/2;
            if(mid_p == 8) break;
            // Get the extreme black points of that diagonal
            begin_r = mid_p > 4 ? 8 : 2*mid_p - 1;
            end_r   = mid_p > 4 ? 2*mid_p - 8 : 1;
            begin_c = mid_p > 4 ? 2*mid_p - 8 : 1;
            end_c   = mid_p > 4 ? 8 : 2*mid_p - 1;

            // If bishop already at one of the extremes, skip that.
            if(curr_r != begin_r && curr_c != begin_c) 
                moves.push_back(make_pair(begin_r, begin_c));
            
            if(curr_r != end_r && curr_c != end_c)
                moves.push_back(make_pair(end_r, end_c));

            curr_c = curr_r = mid_p;
            // Centralize the bishop in that diagonal
            if(curr_c != 1)
                moves.push_back(make_pair(curr_r, curr_c));
            curr_c++;curr_r++;
            // Increment the diagonal
            moves.push_back(make_pair(curr_r, curr_c));
        }   

        curr_c = init_c - 1;
        while(curr_c > 1) {
            mid_p = (curr_r + curr_c)/2;
            // Get the extreme black points of that diagonal
            begin_r = mid_p > 4 ? 8 : 2*mid_p - 1;
            end_r   = mid_p > 4 ? 2*mid_p - 8 : 1;
            begin_c = mid_p > 4 ? 2*mid_p - 8 : 1;
            end_c   = mid_p > 4 ? 8 : 2*mid_p - 1;

            // If bishop already at one of the extremes, skip that.
            if(curr_r != begin_r && curr_c != begin_c) 
                moves.push_back(make_pair(begin_r, begin_c));
            
            if(curr_r != end_r && curr_c != end_c)
                moves.push_back(make_pair(end_r, end_c));

            curr_c = curr_r = mid_p;
            // Centralize the bishop in that diagonal
            moves.push_back(make_pair(curr_r, curr_c));
            // Decrement the diagonal
            curr_c--;curr_r--;
            if(curr_c > 0)
                moves.push_back(make_pair(curr_c, curr_c));
        }
        vector<pair<int, int>>::iterator it = unique(moves.begin(), moves.end());
        moves.resize(distance(moves.begin(), it));
        cout << moves.size() << endl;
        for(int i= 0 ; i < moves.size(); i++) {
            cout << moves[i].first << " " << moves[i].second << endl;
        }
    }

    return 0;
}