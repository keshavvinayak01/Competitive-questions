#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        bool finished[n+1];
        for(int i = 0 ; i <= n ; i++) finished[i] = false;
        
        int arr[m];
        for(int i = 0 ; i < m ; i++) {
            cin >> arr[i];
            finished[arr[i]] = true;
        }
        
        vector<int> m1;
        vector<int> m2;
        bool first = true;
        
        for(int i = 1; i <= n ; i++) {
            if(first && !finished[i]) {
                m1.push_back(i);
                first = !first;
            }
            else if(!first && !finished[i]) {
                first = !first;
                m2.push_back(i);
            }
        }
        
        for(int i = 0 ; i < m1.size(); i++) cout << m1[i] << " ";
        cout << endl;
        
        for(int i = 0 ; i < m2.size(); i++) cout << m2[i] << " ";
        cout << endl;
    }

    return 0;
}