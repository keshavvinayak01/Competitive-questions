#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

struct node{
    int val, index, count;
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
    int t;
    bool ans;
    cin >> t;
    while(t--) {
        int n, p;
        ans = false;
        cin >> n >> p;
        vector<node> arr(n);
        for(int i = 0 ; i < n ; i++) {
            cin >> arr[i].val;
            arr[i].index = i;
        }
        for(int i = 0 ; i < n ; i++) {
            if(p % arr[i].val != 0) {
                ans = true;
                break;
            }
        }
        if(!ans) {
            cout<< "NO\n";
            continue;
        }
        sort(arr.begin(), arr.end(), valueWise);
        int mult;
        for(int i = 0 ; i < n ; i++) {
            if(p % arr[i].val != 0) {
                mult = ceil(float(p)/float(arr[i].val));
                mult = mult > 0 ? mult : 1;
                arr[i].count = mult;
                break;
            }
        }
        
        sort(arr.begin(), arr.end(), indexWise);
        cout << "YES ";
        for(int i = 0 ; i < n ; i++) {
            cout << arr[i].count << " ";
        }
        cout << endl;
    }

    return 0;
}