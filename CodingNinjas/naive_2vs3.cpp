#include<bits/stdc++.h>
using namespace std;
int *dp = new int[10001];
int main(){
    int n;
    cin >> n;
    dp[0] = 1;
    
    string s;
    cin >> s;
    int q;
    cin >> q;
    while(q--) {
        int queryType;
        cin >> queryType;
        if(queryType == 0) {
            int l, r;
            cin >> l >> r;
            char out[r-l+1];
            strcpy(out, s.substr(l,r + 1).c_str());
            cout << out << endl;
            cout << atoi(out)%3 << endl;
        }
        else{
            int x;
            cin >> x;
            s[x] = '1';
        }
    }


    return 0;
}