#include <bits/stdc++.h>

using namespace std;

vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries,
                            int q);

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
    vector<bool> result;
    int i, j;
    for(int k = 0 ; k < q ; k++) {
        i = queries[k].first;
        j = queries[k].second;
        while(arr[i+1] >= arr[i] && i < n) i++;
        while(arr[j-1] >= arr[j] && j > 0) j--;
        result.push_back(i == j);
    }
    return result;
}