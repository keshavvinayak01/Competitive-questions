#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll get_ans(string s, int k, int size){
    if(size == 0){
        return 1;
    }
    
}

int main(){
    int n, c, k;
    cin >> n >> c >> k;
    string s;
    cin >> s;
    cout << get_ans(s, k, s.size()-1) << endl;
    return 0;
}