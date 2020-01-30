#include<bits/stdc++.h>
using namespace std;


int main() {
    int t, temp, n, x;
    bool ans;
    cin >> t;
    while(t--) {
        cin >> n >> x;
        ans = false;
        int arr[100001];
        for(int i = 0 ; i <= 100000; i++) arr[i] = 0;

        for(int i = 0 ; i < n ; i++) {
            cin >> temp;
            arr[temp]++;            
        }
        
        for(int i = 0 ; i <= 100000; i++) {
            if(arr[i] > 0 && i <= x) {
                if(i == x/2 && arr[i] >= 2 && i % 2 == 0) {
                    ans = true;
                    break;
                }
                else if(arr[x - i] > 0 && i != x/2) {
                    ans = true;
                    break;
                }
            }
        }
        if(ans) cout << "Yes\n";
        else    cout << "No\n";
    }

    return 0;
}