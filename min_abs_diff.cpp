#include<bits/stdc++.h>
using namespace std;

int minAbsDiff(int arr[], int n){
    sort(arr, arr+n);
    int min_diff = INT_MAX;
    for(int i=1; i <= n; i++)
        if(arr[i] - arr[i-1] < min_diff)
            min_diff = arr[i] - arr[i-1];

    return min_diff;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i < n; i++)
        cin >> a[i];
    cout << minAbsDiff(a, n);


    return 0;
}
