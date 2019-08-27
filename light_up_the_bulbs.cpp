#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n,x,y;
    cin >> n >> x >> y;
    ll groups = 0;
    string s;
    cin >> s;
    if(s[0] == '0') groups++;
    for(ll i=0; i < n-1; i++){
        if(s[i] == '1' && s[i+1] == '0'){
            groups++;
        }
    }
    if(groups == 0){
        cout << 0;
    }
    else{
        cout << (groups - 1)*min(x, y) + y;
    }
    cout << groups << endl;
    return 0;
}