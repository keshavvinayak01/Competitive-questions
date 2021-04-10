#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n], start;
        bool found = false;
        for(int i = 0 ; i < n ; i++)
            cin >> arr[i];
        start = arr[0];
        for(int i = 1 ; i < n-1; i++) {
            if(arr[i] != start && arr[i+1] != arr[i]) {
                cout << i+1 << endl;
                found = true;
                break;
            }
        }
        if(!found) {
            if(arr[1] != start) {
                cout << 1 << endl;
            }
            else cout << n << endl;
        }
    }
    return 0;
}