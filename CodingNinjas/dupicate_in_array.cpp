// arr - input array
// size - size of array
#include<bits/stdc++.h>
using namespace std;

int MissingNumber(int arr[], int size){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    map<int, int> counts;
    for(int i = 0; i < size; i++){
        counts[arr[i]] = counts[arr[i]] + 1;
    }
    for(int i=0;i<size-2;i++){
        if(counts[arr[i]] > 1){
            return arr[i];
        }
    }
}

int main(){

    int a[] = {1,2,3,4,3,6,7};

    cout<<MissingNumber(a, 7);
    return 0;
}