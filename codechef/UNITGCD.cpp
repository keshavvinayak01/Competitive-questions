#include<iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    
    while(t--) {
        int s;
        cin >> s;
        if (s == 1) printf("%d\n%d %d\n", 1, 1, 1);
        else {
            printf("%d\n", s/2);
            if(s % 2 != 0) printf("%d %d %d %d\n", 3, 1, 2, s);
            else           printf("%d %d %d\n", 2, 1, 2);
            for(int i = 3; i < s ; i += 2) {
                if(i + 1  <= s) printf("%d %d %d\n", 2, i, i+1);
                else if(i <= s) printf("%d %d\n", 1, i);
            }
        }
        
    }
    return 0;
}