#include<bits/stdc++.h>
using namespace std;

int FindUnique(int arr[], int size){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    map<int, int> counts;
    for(int i=0;i<size;i++){
        counts[arr[i]] = counts[arr[i]] + 1;
    }
    for(int i=0; i< size;i++){
        if(counts[arr[i]] == 1){
            return arr[i];
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<FindUnique(arr, n);
    return 0;
}