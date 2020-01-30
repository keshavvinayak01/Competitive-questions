#include<bits/stdc++.h>
using namespace std;

int main() {    
    int t;
    cin >> t;
    int* queries = new int[t];
    for(int i = 0 ; i < t ; i++) {
        cin >> queries[i];
    }
    int* isCube = new int[1000001];
    for(int i = 0; i <= 1000000; i++) isCube[i] = 0;

    int* counts = new int[1000001];
    int runningCount = 0;

    for(int i = 2 ; i <= 100; i++) {
        for(int j = i*i*i; j <= 1000000; j += i*i*i) {
            isCube[j] = -1;
        }
    }
    
    for(int i = 1 ; i <= 1000000; i++) {
        if(isCube[i] == 0) {
            counts[i] = ++runningCount;
        }
    }

    for(int i = 0 ; i < t ; i++) {
        if(isCube[queries[i]] == -1) {  
            cout << "Case " << i + 1 << ": Not Cube Free" << endl;
        }
        else {
            cout << "Case " << i + 1 << ": " << counts[queries[i]] << endl;
        }
    }
    return 0;
}