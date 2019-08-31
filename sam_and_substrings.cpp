#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long substrings(string s){
    long long totalSum = s[0] - '0';
    long long lastValue = s[0] - '0';
    for(int i=1; i < s.length(); i++ ){
        lastValue = (lastValue*10 + (s[i] - '0')*(i+1))%MOD;
        totalSum = (totalSum + lastValue)%MOD;        
    }
    return totalSum;
}

int main(){


    return 0;
}