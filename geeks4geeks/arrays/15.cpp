#include <bits/stdc++.h>

using namespace std;

vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries, int q);

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, i, q;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> q;
        vector<pair<int, int>> queries(q);
        for (i = 0; i < q; i++) {
            cin >> queries[i].first >> queries[i].second;
        }
        auto v = processQueries(a, n, queries, q);
        for (bool u : v) {
            cout << (u ? "Yes\n" : "No\n");
        }
    }
    return 0;
}// } Driver Code Ends


vector<bool> processQueries(int arr[], int n, vector<pair<int, int>> &queries,
                            int q) {
    int leftPtr = 0, rightPtr = n-1;
    int* left = new int[n];
    int* right = new int[n];
    left[0] = 0; right[n-1] = n-1;
    
    // Setting Left array
    for(int i = 1 ; i < n; i++) {
        if(arr[i] > arr[i-1]) leftPtr = i;
        left[i] = leftPtr;
    }
    
    // Setting Right array
    for(int i = n-2 ; i >= 0; i--) {
        if(arr[i] > arr[i+1]) rightPtr = i;
        right[i] = rightPtr;
    }

    // Setting the boolean result array
    vector<bool> result(q);
    for(int i = 0 ; i < q; i++)
        result[i] = right[queries[i].first] >= left[queries[i].second]; 
    
    // for(int i = 0 ; i < n ; i++) cout << left[i] << " ";
    // cout << endl;

    // for(int i = 0 ; i < n ; i++) cout << right[i] << " ";
    // cout << endl;
    
    delete[] left;
    delete[] right;
    return result;
}