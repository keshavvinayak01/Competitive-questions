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
    int first = coin_change(n-d[0], d, numD);
    int second = coin_change(n, d+1, numD - 1);
    output[n][numD] = first + second;
    return first + second;
}

int main(){
    int n, d;
// allocate 2d array of size n+1 * numD + 1, put all -1
    return 0;
}