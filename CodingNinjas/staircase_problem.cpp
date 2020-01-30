#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solveStaircase(int n, ll* output){
    if(output[n] != -1){
        return output[n];
    }
    ll ans = solveStaircase(n-1, output) + solveStaircase(n-2, output) + solveStaircase(n-3, output);
    output[n] = ans;
    return ans;
}

long staircase(int x){
    int n = x + 1;
    ll* output = new ll[n];
    for(int i=0; i < n;i++)
        output[i] = -1;
    output[0] = 1;
    output[1] = 1;
    output[2] = 2;
    output[3] = 4;
    ll ans =  solveStaircase(x, output);
    delete[] output;
    return ans;
}


int main(){

    int n;
    cin >> n;
    cout << stairCase(n) << endl;

    return 0;
}