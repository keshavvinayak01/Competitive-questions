// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


int transitionPoint(int arr[], int n) {
    int left = 0, right = n-1, mid;
    while(right >= left) {
        mid = (right + left)/2;
        if(arr[mid] == 1 && arr[mid - 1] == 0) return mid;
        else if(arr[mid] == 1)
            right = mid-1;
        else if(arr[mid] == 0)
            left = mid +1;
    }
    return -1;
}