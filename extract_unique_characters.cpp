#include<bits/stdc++.h>

using namespace std;

char* uniqueChar(char *str){
    // Write your code here
    int a[128];
    for(int i=0;i<128;i++){
        a[i] = 0;
    }
    for(int i=0 ; str[i] != '\0' ; i++){
        a[int(str[i])] += 1;
    }
    for(int i = 0)
    return str;
}

int main(){
    string s;
    cin>>s;
    char pass[s.size() + 1];
    strcpy(pass, s.c_str());
    cout<<uniqueChar(pass)<<endl;
    return 0;
}