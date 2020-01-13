#include<bits/stdc++.h>
using namespace std;

bool cmpOp(int a, int b) {
    return a > b;
}

bool canMug(int arr[], int n, int currSum, int reqSum) {
    if(n < 0 || currSum == reqSum) {
        if(currSum == reqSum) return true;
        else return false;
    }
    return canMug(arr+1, --n, currSum + arr[0], reqSum) || 
            canMug(arr+1, --n, currSum, reqSum);
    
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int arr[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        
        sort(arr, arr + n);
        if(canMug(arr, n, 0, m)) {
            cout << "Yes\n";
        }
        else {
            sort(arr, arr + n, cmpOp);
            if(canMug(arr, n, 0, m)) {
                cout << "Yes\n";
            }    
            else cout << "No\n";
        }
    }

    return 0;
}