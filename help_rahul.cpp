#include<bits/stdc++.h>
using namespace std;

int binarySearch(int start, int end, int* arr, int k) {
    if(start == end && arr[start] == k) {
        return start;
    }
    if(start >= end) {
        return -1;
    }
    int mid = (start+end)/2;
    if(k > arr[mid]) return binarySearch(mid+1, end, arr, k);
    if(k < arr[mid]) return binarySearch(start, mid, arr, k);
    else return mid;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    int k;
    cin >> k;
    int start = -1;
    int ans = -1;
    int i = 0;
    while(i < n && arr[i+1] > arr[i]) {
        if(arr[i] == k) {
            ans = i;
            break;
        }
        i++;
    }
    if(i < n-1) start = i;
    if(ans >= 0) {
        cout << ans << endl;
    }
    else {
        cout << binarySearch(start, n, arr, k) << endl;
    }
    return 0;
}