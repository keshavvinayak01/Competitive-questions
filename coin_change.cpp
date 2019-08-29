#include<bits/stdc++.h>
using namespace std;

int coin_change(int n, int* d, int numD, int** output){
    if(n == 0){
        return 1;
    }
    if(numD == 0 || n < 0){
        return 0;
    }
    if(output[n][numD] > -1){
        return output[n][numD];
    }
    int first = coin_change(n-d[0], d, numD, output);
    int second = coin_change(n, d+1, numD - 1, output);
    output[n][numD] = first + second;
    return first + second;
}

int countWaysToMakeChange(int denominations[], int numD, int n){
    int** output = new int* [n+1];
    for(int i=0; i < n+1; i++)
        output[i] = new int[numD+1];
    for(int i=0; i<n+1; i++)
        for(int j=0; j<numD + 1; j++)
            output[i][j] = -1;
    int ans = coin_change(n,denominations, numD, output);
    return ans;
}
int main(){
    int numD, n;
    cin >> numD;
    int d[numD];
    for(int i=0; i<numD;i++)
        cin >> d[i];
    cin >> n;
    cout << countWaysToMakeChange(d, numD, n) << endl;
// allocate 2d array of size n+1 * numD + 1, put all -1
    return 0;
}