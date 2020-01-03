#include<bits/stdc++.h>
using namespace std;

int main() {    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
		if(n == 1) {
			cout << 1 << endl;
			continue;
		}
        int max, steps = 0;
        while(n > 1) {
            max = 1;
            while(max < n) {
                max *= 2;
            }
            if(max > n) max /= 2;
            n -= max;
            steps++;
        }
        if(n == 1) steps++;
        cout << steps << endl;
    }
    return 0;
}