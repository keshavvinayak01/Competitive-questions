#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    int n;
    cin >> n;
    int a[n];
    for(int i=0; i < n; i++)
        cin >>a[i];
    ll lcount = 0;
    ll rcount = 0;
    for(int i=0; i < n;i++){
        int pos = a[i] - i - 1;
        if(pos > 0 && pos <= 2){
            lcount += pos;
        }
        else if(pos < 0 && pos >= -2){
            rcount += pos;
        }
    }
    if(lcount + rcount == 0){
        cout << "YES\n"<<lcount<<endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}