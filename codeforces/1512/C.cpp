#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;


int main() {
    int t, count[2], size, zeros, ones;
    cin >> t;
    while(t--) {
        cin >> count[0] >> count[1];
        zeros = count[0];
        ones = count[1];
        string s;
        cin >> s;
        size = s.length();
        // calc number of actual 0s and 1s to be input 
        for(int i = 0 ; i < size; i++) 
            if(s[i] != '?') count[s[i] - '0']--;
        
        // invalid string given
        if(count[0] < 0 || count[1] < 0) {
            cout << -1 << endl;
            continue;
        }
        // replace string values accordingly
        bool np = false;
        for(int i = 0 ; i <= size/2 ; i++) {
            if(np) break;
            // 1. both are ?
            if(s[i] == s[size - i -1] && s[i] == '?') {
                if(size%2 != 0 && i == size/2) {
                    if(count[0] == 1) s[i] = '0';
                    else if(count[1] == 1) s[i] = '1';
                    else np = true;
                    count[s[i] - '0']--;
                }
                else if(count[0] >= 2) {
                    count[0] -= 2;
                    s[i] = '0';
                    s[size - i - 1] = '0';
                }
                else if(count[1] >= 2) {
                    count[1] -= 2;
                    s[i] = '1';
                    s[size - i - 1] = '1';
                }
                // Not possible error
                else 
                    np = true;
            }
            // 2. one of them is ?
            else if((s[i] == '?' && s[size - i - 1] != '?') || s[i] != '?' && s[size - i - 1] == '?') {
                if(s[i] == '?') {
                    s[i] = s[size - i - 1];
                }
                else {
                    s[size - i - 1] = s[i];
                }
                count[s[i] - '0']--;
            }
            // 3. both are already fixed

            if(count[0] < 0 || count[1] < 0)
                np = true;
        }
        if(np) 
            cout << -1 << endl;
        else {
            int act_count[2];
            act_count[0] = 0;
            act_count[1] = 0;
            for(int i = 0 ; i < size; i++)
                act_count[s[i] - '0']++;
            if(zeros != act_count[0] || ones != act_count[1])
                cout << -1 << endl;

            else {
                // Perform final check if pallindrome
                
                bool is = true;
                for(int i = 0 ; i <= size/2; i++)
                    if(s[i] != s[size - i - 1]) {
                        is = false;
                        cout << -1 << endl;
                        break;
                    }
                
                if(is)
                    cout << s << endl;
            }
        }
        
    }
    return 0;
}