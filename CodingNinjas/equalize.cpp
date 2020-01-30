#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int cost = 0;
    for(int i=0; i < n;){
        if(s[i] != t[i]){
            if(i+1 < n && s[i] != s[i+1] && s[i+1] != t[i+1]){
                i += 2;
            }
            else{
                i++;
            }
            cost++;
        }
        else{
            i++;
        }
    } 

    cout << cost << endl;
    return 0;
}