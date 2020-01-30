#include<bits/stdc++.h>
using namespace std;

int getMaxDivisibleSubArrays(int* arr, int n) {
    int mod[n];
    for(int i = 0 ; i < n ; i++) {
        mod[i] = 0;
    }
    int cumSum = 0;
    for(int i = 0 ; i < n ; i++) {
        cumSum += arr[i];
        mod[(cumSum%n + n)%n]++;
    }
    int result = 0;
    for(int i = 0; i < n ; i++) {
        if(mod[i] > 1) 
            result += (mod[i]*(mod[i] - 1))/2;
    }
    result += mod[0];
    return result;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int *arr = new int[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        cout << getMaxDivisibleSubArrays(arr, n) << endl;
    }
    return 0;
}