#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n;
        int arr[3];
        arr[0] = arr[1] = arr[2] = 0;
        for(int i = 0 ; i < n ; i++) {
            cin >> x;
            arr[x]++;
        }
        for(int i = 0 ; i <= 2 ; i++) {
            for(int j = 0 ; j < arr[i]; j++) {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}