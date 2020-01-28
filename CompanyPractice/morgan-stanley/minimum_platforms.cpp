#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n, max_count;
    int counts[3000];
    string temp;
    cin >> t;
    while(t--) {
        max_count = -1;
        int n;
        cin >> n;
        int arr[n], dep[n];
        for(int i = 0 ; i < n ; i++) {
            cin >> temp;
            arr[i] = stoi(temp);
        }
        for(int i = 0 ; i < n ; i++) {
            cin >> dep[i];
        }
        for(int i = 1 ; i <= 3000; i++) counts[i] = 0;
        
        for(int i = 0 ; i < n ; i++) {
            for(int j = arr[i]; j <= dep[i]; j++) {
                counts[j]++;
                if(counts[j] > max_count) max_count = counts[j];
            }
        }
        cout << max_count << endl;
    }

    return 0;
}