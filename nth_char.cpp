#include<bits/stdc++.h>
using namespace std;
int* dp = new int[500];

char* characterAt(char* input1, int input2){
    char *str = (char*)malloc(sizeof(char)*2);
    int total = 0;
    for(int i = 0; input1[i] != '\0'; i++){
        if(i%2 != 0){
            total += input1[i] - '0';
        }
        else{
            dp[input1[i]] += input1[i+1] - '0'; 
        }
    }
    for(int i = 0 ; i < 500; i++){
        if(total < input2 || total < dp[i]){
            *(str + 0) = char(i);
            return str;
        }
        if(dp[i] > 0){
            total -= dp[i];
        }
    }
    *str = '-';
    *(str + 1) = '1';
    return str;
}

int main(){
    char *str = (char*)malloc(sizeof(char)*6);
    cin >> str;    
    cout << characterAt(str, 5) << endl;
    return 0;
}