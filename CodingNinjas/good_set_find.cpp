/*
    You are given array a consisting of n distinct integers. A set s of numbers is called good 
    if you can rearrange the elements in such a way that each element divides the next element 
    in the order, i.e. 'si' divides 'si + 1', such that i < |s|, where |s| denotes size of set |s|.
    Find out number of distinct good sets that you can create using the values of the array. You 
    can use one value only once in a particular set; ie. a set cannot have duplicate values. Two 
    sets are said to be different from each other if there exists an element in one set, which 
    does not exist in the other.

    As the answer could be large, print your answer modulo 10^9 + 7.
*/

#include<bits/stdc++.h>
#define MOD 1000000007;
typedef long long ll;

using namespace std;

ll nGoodSets(int* arr, int n) {
    sort(arr, arr+n);
    int max_el = arr[n-1];

    ll* sets = new ll[max_el + 1];
    
    for(int i = 0 ; i < n; i++) sets[arr[i]] = 1;
    
    sets[0] = 0;

    for(int i = 0 ; i < n ; i++) {
        for(int j = arr[i]*2; j <= max_el; j += arr[i]) {
            if(sets[j] > 0) {
                sets[j] += sets[arr[i]]%MOD;
                sets[j] = sets[j]%MOD;
            }
        }
    }
    

    ll ans = 0;
    for(int i = 1 ; i <= max_el; i++) {
        ans  += sets[i]%MOD;
        ans = ans%MOD
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int* arr = new int[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        cout << nGoodSets(arr, n) << endl;
    }


    return 0;
}