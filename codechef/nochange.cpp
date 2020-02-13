#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

struct node{
    lli val, index, count;
    node() {
        count = 0;
    }
};

bool valueWise(node a, node b) {
    return a.val > b.val;
}

bool indexWise(node a, node b) {
    return a.index < b.index;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli t, mult, n, p;
    cin >> t;
    while(t--) {
        cin >> n >> p;
        vector<node> arr(n);
        for(int i = 0 ; i < n ; i++) {
            cin >> arr[i].val;
            arr[i].index = i;
        }
        sort(arr.begin(), arr.end(), valueWise);
        for(int i = 0 ; i < n && p > 0; i++) {
            if(p % arr[i].val != 0) {
                if(p >= 1000000000) {
                    mult = p/arr[i].val + 1;     
                }
                else {
                    mult = ceil(float(p)/arr[i].val);
                }
                arr[i].count += mult;
                p -= mult*arr[i].val;
            }
            else {
                mult = p/arr[i].val - 1;
                arr[i].count += mult;
                p -= arr[i].val*mult;
            }
            
        }
        if(p < 0) {
            sort(arr.begin(), arr.end(), indexWise);
            cout << "YES ";
            for(int i = 0 ; i < n ; i++) {
                cout << arr[i].count << " ";
            }
            cout << endl;
        }
        else {
            cout << "NO\n";
        }        
    }
    return 0;
}