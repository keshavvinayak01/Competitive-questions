#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long countArray(int n, int k, int x){
    long oneCount = 1;
    long nonOneCount = 0;
    for(int i=0; i < n; i++){
        long prevOneCount = oneCount
        oneCount = (nonOneCount*(k-1))%MOD;
        nonOneCount = (prevOneCount + (nonOneCount*(k-2))%MOD)%MOD;
    }
    if(x == 1){
        return oneCount;
    }
    return nonOneCount;
}

int main(){
    int n;


    return 0;
}