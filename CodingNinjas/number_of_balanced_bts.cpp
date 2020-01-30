#include<bits/stdc++.h>
using namespace std;

long long x = pow(10,9) + 7;

int balancedBTs(int n){
    if(n <=1){
        return 1;
    }

    return ((balancedBTs(n-1)%x)*(balancedBTs(n-1)%x))%x + 2*(((balancedBTs(n-1)%x)*(balancedBTs(n-2)%x))%x);
}

int main(){
    int n;
    cin >> n;

    cout << balancedBTs(n) << endl;

    return 0;
}