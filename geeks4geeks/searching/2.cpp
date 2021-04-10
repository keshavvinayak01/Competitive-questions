// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
  public:
    int findExtra(int a[], int b[], int n) {
        // Size of array B is n-1
        /* Algorithm :  
            1. Do parallel binary search on both arrays
            2. if the middle element is same, move ahead
            3. If the middle element for A is larger/smaller, move behind
        */
        int left = 0, right = n-2, mid;
        while(right >= left) {
            mid = (right + left)/2;
            if(a[mid] == b[mid])
                left = mid+1;
            else if(a[mid+1] == b[mid] && a[mid] == b[mid-1]) right = mid-1;
            else return mid;
        }
        return n-1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> b[i];
        }
        Solution obj;
        cout << obj.findExtra(a, b, n) << endl;
    }
}  // } Driver Code Ends