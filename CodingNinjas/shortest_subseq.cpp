#include<bits/stdc++.h>
using namespace std;


int scs(char* s1, char* s2, int m, int n){
    if(s1[0] == '\0' || s2[0] == '\0'){
        return 0;
    }
    int option1 = scs(s1+1, s2, m-1, n);
    int option2 = INT_MAX;
    int i = 0;
    for(i; s2[i] != s1[0] && i < n; i++);
    if(i == n){
        return option1;
    }
    option2 = (n-i) + scs(s1+1, s2+i, m-1, n);
    ans = min(ans, option2);
    return min(option1, option2);
}

int main(){
    string s, v;
    cin >> s;
    cin >> v;
    int m = s.length();
    int n = v.length();

    char s1[m+1], s2[n+1];
    strcpy(s1, s.c_str());
    strcpy(s2, v.c_str());

    scs(s1, s2, m, n);
    cout << ans << endl;
    return 0;
}