#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

void removeDuplicate(vector<int> &vect) {
    vector<int> temp;
    int counts[101];
    memset(counts, 0, sizeof(counts));
    for(int i = 0 ; i < vect.size() ; i++) {
        if(counts[vect[i]] == 0) {
            temp.push_back(vect[i]);
        }
            counts[vect[i]] += 1;
    }
    vect = temp;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        removeDuplicate(arr);
        for(int i = 0 ; i < arr.size() ; i++) cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}