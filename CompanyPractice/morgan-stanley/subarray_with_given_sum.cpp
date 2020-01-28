#include<bits/stdc++.h>
typedef unsigned long long int lli;
using namespace std;

int main() {
    lli t, n, s, currSum, start, end;
    cin >> t;
    while(t--) {
        cin >> n >> s;
        lli arr[n];
        for(int i = 0; i < n ; i++) cin >> arr[i];
        int i = 0, j = 1;
        start = 0; end = 1;
        currSum = arr[i];
        if(currSum == s) {
            cout << 1 << " " << 1 << endl;
            continue;
        }
        while(i < n && j < n) {
            currSum += arr[j];
            while(currSum > s) {
                currSum -= arr[i];
                i++;
            }
            start = i;
            end = j;
            j++;
            if(currSum == s) break;
        }
        if(currSum == s)
            cout << start + 1<< " " << end + 1 << endl;
        else cout << -1 << endl;
    }
}