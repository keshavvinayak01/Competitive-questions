#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

struct el {
    int a, b, c;
};

bool sortThis(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.first < b.first;
}

bool sortOld(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.second.first < b.second.first;
}

bool Sorted(pair<int, pair<int, int>> arr[], int n, vector<int> check) {
    for(int i = 0 ; i < n ; i++) {
        if(arr[i].first != check[i]) return false;
    }
    return true;
}
void printAns(vector<el> operations) {
    int x, y, z;
    cout << operations.size() << endl;
    for(int i = 0 ; i < operations.size(); i++) {
        cout << operations[i].a + 1<< " " << operations[i].b + 1 << " " << operations[i].c+1 << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, x, y, z, ans1, ans2, ans3;
    cin >> t;
    while(t--) {
        ans1 = true;
        int n, k;
        cin >> n >> k;
        pair<int, pair<int, int>> arr[n];
        bool f;
        int arr_orig[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i].first;
        int pos[n];
        for(int i = 0 ; i < n ; i++) {
            arr[i].second.first = i;
            arr_orig[i] = arr[i].first;
        }

        sort(arr, arr + n, sortThis);
        for(int i = 0 ; i < n ; i++) {
            arr[i].second.second = i;
        }
        sort(arr, arr + n, sortOld);

        int fp, cp, ap, temp1, temp2, temp3;
        vector<el> operations;
        vector<int> temp(n), pos_u(200001), pos_s(200001);
        for(int i = 0 ; i < n ; i++) temp[i] = arr[i].first;
        sort(temp.begin(), temp.end());
        for(int i = 0 ; i < n ; i++) pos_u[arr[i].first] = i;
        for(int i = 0 ; i < n ; i++) pos_s[temp[i]] = i;
        for(int i = 0 ; i < n ; i++) {
            if(arr[i].first == temp[i]) continue;
            fp = pos_u[temp[i]];
            cp = i;
            ap = pos_s[arr[i].first];
            if(fp == ap) {
                ap = cp + 1;
            }
            temp1 = arr[fp].first;
            temp2 = arr[cp].first;
            temp3 = arr[ap].first;
            if(fp == cp || fp == ap || ap >= n){
                ans1 = false;
                break;
            }
            if((ap > cp && ap > fp)) {
                operations.push_back({fp, cp, ap}); 
                operations.push_back({fp, cp, ap}); 
                arr[cp].first = temp1;
                arr[ap].first = temp2;
                arr[fp].first = temp3;
                pos_u[temp1] = cp;
                pos_u[temp2] = ap;
                pos_u[temp3] = fp;
            }
            else {
                operations.push_back({fp, cp, ap}); 
                arr[cp].first = temp1;
                arr[ap].first = temp2;
                arr[fp].first = temp3;
                pos_u[temp1] = cp;
                pos_u[temp2] = ap;
                pos_u[temp3] = fp;
            }
        }
        if(operations.size() > k || !ans1 || !Sorted(arr, n, temp)) {
            cout << -1 << endl;
            continue;
        }
        else {
            printAns(operations);
        }
    }
    return 0;
}