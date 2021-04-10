#include <bits/stdc++.h>
using namespace std;
vector<int> duplicates(int arr[], int n);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> ans = duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


vector<int> duplicates(int a[], int n) {
    int arr[n], empty = 0;
    for(int i = 0 ; i < n ; i++) arr[i] = 0;
    for(int i = 0 ; i < n ; i++) {
        arr[a[i]]++;
    }
    vector<int> result;
    for(int i = 0 ;  i < n ; i++) {
        if(arr[i] > 1) {
            result.push_back(i);
            empty++;
        }
    }
    if(empty > 0)
        return result;
    result.push_back(-1);
    return result;
}
