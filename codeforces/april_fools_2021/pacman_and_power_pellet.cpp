#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

struct position {
    pair<int, int> pos;
    int steps;
    position() {
        steps = 0;
    }
};  
stack<position> togo;
char pacmap[200][200];
bool visited[200][200];
int n, m;

stack<position> validate_and_push(int i, int j, int step) {
    // printf("position is %d, %d\nCharacter: %c\nvisited: %d\nsteps: %d\n\n", i, j, pacmap[i][j], visited[i][j], step);
    if(i >= 0 && i < n && j >= 0 && j < m && pacmap[i][j] != '#' && !visited[i][j]) {
        position temp;
        temp.pos = make_pair(i, j);
        temp.steps = step;
        togo.push(temp);
        visited[i][j] = true;
    }    
    return togo; 
}

int main() {
    int curr_steps = 0, ans = INT_MAX;
    bool found = false;
    char inp;
    position start, curr, temp;
    memset(pacmap, '#', 200*200*sizeof(char));
    memset(pacmap, false, 200*200*sizeof(bool));
    
    cin >> n >> m;
    
    start.steps = 0;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++) {
            cin >> inp;
            pacmap[i][j] = inp;
            if(inp == 'P') {
                start.pos.first = i;
                start.pos.second = j;
                visited[i][j] = true;
            }
        }
    // cout << "here's the pacmap: \n";
    // for(int i = 0 ; i < n ; i++) {
    //     for(int j = 0  ; j < m ; j++) {
    //         cout << pacmap[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
        
    // Perform BFS
    togo.push(start);
    while(!togo.empty()) {
        curr = togo.top();
        togo.pop();
        curr_steps++;
        if(pacmap[curr.pos.first][curr.pos.second] == 'O') {
            found = true;
            ans = min(ans, curr.steps);
        }
        // check top
        togo = validate_and_push(curr.pos.first - 1, curr.pos.second, curr_steps);
        // check bottom
        togo = validate_and_push(curr.pos.first + 1, curr.pos.second, curr_steps);
        // check left 
        togo = validate_and_push(curr.pos.first, curr.pos.second - 1, curr_steps);
        // check right
        togo = validate_and_push(curr.pos.first, curr.pos.second + 1, curr_steps);
    }
    if(found) cout << ans;
    else cout << -1;
    cout << "\n";
    return 0;
}