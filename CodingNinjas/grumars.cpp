#include<bits/stdc++.h>
using namespace std;


int main() {
    int q;
    cin >> q;
    string s = "";
    int ans = 1;
    int* alphaCount = new int[26];
    for(int i = 0 ; i < 26; i++) alphaCount[i] = 0;
    while(q--) {
        string a;
        cin >> a;
        for(int i = 0 ; i < a.size(); i++) {
            alphaCount[a[i] - 'A']++;
        }
        
    }

    return 0;
}