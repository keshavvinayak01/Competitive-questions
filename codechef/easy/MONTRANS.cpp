#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b, c, steps = 0, max_step = 0, curr, max_curr;
    cin >> t;
    while(t--) {
        steps = max_step = 0;
        cin >> a >> b >> c;
        curr = a*100 + b;
        max_curr = curr;
        max_step = steps = 0;
        while(true) {
            if(curr < c) break;
            steps++;
            curr -= c;
            curr = curr/100 + (curr % 100) * 100;
            if(steps >= 10000) break;
            if(curr > max_curr) {
                max_curr = curr;
                max_step = steps;
            }
        }
        cout << max_step << endl;
    }
}