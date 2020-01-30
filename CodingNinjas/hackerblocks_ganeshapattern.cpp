#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int gap = (n+1)/2 -2;

    cout << "*";    
    for(int i = 0 ; i < (n+1)/2 -2; i++) cout << " ";
    for(int i = 0 ; i < (n+1)/2; i++) cout << "*";
    cout << "\n";
    
    for(int i = 0 ; i < gap; i++) {
        cout <<"*";
        for(int i = 0 ; i< (n+1)/2 -2; i++) cout << " ";
        cout <<"*\n";
    }
    
    for(int i = 0 ; i < n ; i++) cout << "*";
    cout << endl;
    
    for(int i = 0 ; i < gap; i++) {
        for(int i = 0 ; i< gap+1; i++) cout << " ";
        cout << "*";
        for(int i = 0 ; i< gap; i++) cout << " ";
        cout << "*\n";
    }
    
    for(int i = 0 ; i < gap + 2; i++) cout << "*";
    for(int i = 0 ; i < gap ; i++) cout << " ";
    cout << "*\n";
    return 0;
}