#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

void merge(int* arr, int start, int mid, int end) {
    int i = start, j = mid, k = 0;
    int temp[end - start + 1];
    while(i < mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }
    while(i < mid) temp[k++] = arr[i++];
    while(j <= end) temp[k++] = arr[j++];

    for(int i = start, k = 0 ; i <= end; i++, k++) {
        arr[i] = temp[k];
    }
}

void merge_sort(int* arr, int start, int end) {
    if(end > start) {
        int mid = (start + end)/2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);
        merge(arr, start, mid+1, end);
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int* arr = new int[n + m];
        for(int i = 0 ; i < n + m ; i++) cin >> arr[i];
        merge_sort(arr, 0, n + m -1);
        for(int i = 0 ; i < n + m; i++) cout << arr[i] << " ";
        cout << endl;
        delete[] arr;
    }

    return 0;
}