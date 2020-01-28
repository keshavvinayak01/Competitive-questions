#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, i;
    string s, word = "";
    cin >> t;
    while(t--) {
        cin >> s;
        i = 0;
        stack<string> ans;
        while(i < s.size()) {
            word = "";
            while(s[i] != '.' && i < s.size()) {
                word += s[i];
                i++;
            }
            ans.push(word);
            i++;
        }
        while(!ans.empty()) {
            word = ans.top();
            ans.pop();
            cout << word ;
            if(!ans.empty()) cout << ".";
        }
        cout << endl;
    }
    return 0;
}