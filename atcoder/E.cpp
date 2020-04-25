#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

struct el {
    bool occ;
    int val, pos;
}

bool sortThis(pair<lli, lli> a, pair<lli, lli> b) {return a.second > b.second;}

lli getMaxPosition(pair<lli, lli> x, pair<lli, lli> arr[], lli n) {
    lli max_pos = -1, max_val = INT_MIN, temp;
    for(int i = 0 ; i < n ; i++) {
        if(i != x.first) {
            cout << i << " " << arr[i].second << " " << x.first << " " << x.second << endl;
            temp = x.second*(abs(i - x.first)) + arr[i].second*(abs(i - x.first));
            if(temp > max_val) {
                max_val = temp;
                max_pos = i;  
            }
        } 
    }
    occupied[max_pos] = true;
    occupied[x.first] = true;
    return max_val;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli n, temp;
    cin >> n;
    pair<lli, lli> arr[n], arr2[n];
    for(int i = 0 ; i < n ; i++) {
        cin >> temp;
        arr[i] = {i, temp};
        arr2[i] = {i, temp};
    }
    sort(arr, arr + n, sortThis);
    bool* occupied = new bool[n];
    memset(occupied, false, sizeof(occupied));
    lli res = 0;
    for(int i = 0 ; i < n/2 ; i++) {
        res += getMaxPosition(occupied, arr[i], arr2, n);   
    }
    cout << res << endl;
    return 0;
}