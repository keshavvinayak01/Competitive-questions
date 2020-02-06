#include<bits/stdc++.h>
typedef unsigned long long int lli;
#define MOD 1000000007
using namespace std;

lli merge(lli* arr, int start, int mid, int end) {
    int i = start;
    int j = mid;
    lli temp[end - start + 1];
    int k = 0;
    lli count = 0;
    while(i < mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            count += mid - i;
        }
    }
    while(i < mid) temp[k++] = arr[i++];
    while(j <= end) temp[k++] = arr[j++];
    
    for(int i = start, k = 0 ;  i <= end; i++, k++) {
        arr[i] = temp[k];
    }
    return count;
}

lli merge_sort(lli* arr, int start, int end) {
    if(start < end) {
        int mid = (start + end)/2;
        lli ans1 = merge_sort(arr, start, mid);
        lli ans2 = merge_sort(arr, mid+1, end);
        lli myCount = merge(arr, start, mid+1, end);
        return ans1 + ans2 + myCount; 
    }
    return 0;
}


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n, i, j, ans;
    cin >> t;
    while(t--) {
        cin >> n;
        lli* arr = new lli[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        lli ans = merge_sort(arr, 0, n-1);
        cout << ans << endl;
        delete[] arr;
    }

    return 0;
}