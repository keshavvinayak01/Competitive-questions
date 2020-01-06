#include<bits/stdc++.h>
using namespace std;

void buildZ(int* Z, string str) {
    int l = 0, r = 0;
    int n  =  str.length();
    for(int i = 1 ; i < n ; i++) {
        if(i > r) {
            l = r = i;
            while(r < n && str[r-l] == str[r]) {
                r++;
            }
            Z[i] = r - l;
            r--;
        }
        else {
            int k = i - l; 
            if(Z[k] <= r - i) {
                Z[i] = Z[k];
            }
            else {
                l = i;
                while(r < n && str[r-l] == str[r]) {
                    r++;
                }
                Z[i] = r-l;
                r--;
            }
        }
        
    }
}

void searchString(string text, string pattern) {
    string str = pattern + "$" + text;
    int n = str.length();
    int* Z = new int[n];
    buildZ(Z, str);
    for(int i = 0 ; i < n ; i++) {
        if(Z[i] == pattern.length()) {
            cout << i - pattern.length() - 1 << " ";
        }
    }
    cout << endl;
}

int main() {

    return 0;
}