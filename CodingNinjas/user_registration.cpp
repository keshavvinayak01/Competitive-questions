#include<bits/stdc++.h>
using namespace std;



int main(){
    map<string, int> counts;
    int n;
    cin >> n;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(counts[s] > 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        counts[s] = counts[s] + 1;
    }
    return 0;
}