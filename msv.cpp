#include<bits/stdc++.h>
using namespace std;
// typedef long long ll;



int main(){
    int t;
    cin >> t;
    int n;
    while(t--){
        int *counts = new int[1000001];
        bool *exists = new bool[1000001];
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            exists[a[i]] = true;
        }
        int max_count = INT_MIN;
        for(int i = 0 ; i < n; i++){
            vector<int> factors;
            for(int k = 1; k <= int(sqrt(a[i])); k++){
                if(a[i]%k == 0){
                    factors.push_back(k);
                    if(int(a[i]/k) != k) factors.push_back(int(a[i]/k));
                }
            }
            for(int j = 0 ; j < factors.size(); j++){
                counts[factors[j]]++;
            }
            if(counts[a[i]] > max_count && exists[a[i]]){
                max_count = counts[a[i]] -1 ;
            }
        }
        cout << max_count << endl;
        delete[] counts;
    }

    return 0;
}