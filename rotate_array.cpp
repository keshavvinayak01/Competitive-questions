#include<bits/stdc++.h>

using namespace std;


void Rotate(int arr[], int d, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing the output is handled automatically.
     */
    for(int j=0;j<d;j++){
        int temp = arr[0];
        for(int i=0; i < size - 1; i++){
            arr[i] = arr[i+1];
        }
        arr[size - 1] = temp;
    }
    for(int i=0;i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}	


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0 ; i<n ; i++)
        cin>>a[i];
    int d;
    cin>>d;
    Rotate(a, d, n);
    return 0;
}