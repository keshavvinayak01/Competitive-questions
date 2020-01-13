#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int arr[n+1];
    for(int i = 1 ; i <= n ; i++) cin >> arr[i];

    int marks[n+2];
    marks[0] = 0;
    marks[1] = 1;
    marks[n+1] = 0;
    
    for(int i = 2 ; i <= n ; i++) {
        if(arr[i] > arr[i-1]) { 
            marks[i] = 1;
        }
        else marks[i] = 0;
    }

    int increasing = 0, decreasing = 0;
    int l, r;

    // for(int i = 0 ; i <= n+1 ; i++) cout << marks[i] << " ";

    while(q--) {
        increasing = decreasing = 0;
        cin >> l >> r;
        for(int i = l ; i <= r; i++) {
            if((marks[i-1] == 0 || arr[i-1] < arr[i]) && marks[i] == 1) increasing++;

            if((marks[i-1] == 1 || arr[i-1] > arr[i]) && marks[i] == 0) decreasing++;
        }
        if(increasing == decreasing) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}               