#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){

    ll n, d;
    cin >> n >> d;
    int a[d];
    for(int i=d-1; i>=0; i--){
        if(i == 0){
            a[i] = n;
            n = 0;
        }
        else if(n == 1 && i > 0){
            a[i] = 0;
        }
        else if(n > 9) {
            a[i] = 9;
            n -= 9;
        }
        else{
            a[i] = n - 1;
            n = 1;
        }
    }
    for(int i = 0 ; i < d ; i++)
        cout << a[i];
    cout << endl;
    return 0;
}