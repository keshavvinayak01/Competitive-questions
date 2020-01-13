#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n;
        int arr[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        cin >> k;
        int toFind = arr[k-1];
        sort(arr, arr+n);
        for(int i = 0 ; i < n ; i++) {
            if(arr[i] == toFind) {
                cout << i + 1 << endl;
                break;
            }
        }
    }

    return 0;
}