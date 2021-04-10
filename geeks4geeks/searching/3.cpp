// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    // The function should do the stated modifications in the given array arr[]
    // Do not return anything.
    
    // arr[]: Input Array
    // N: Size of the Array arr[]
    //Function to segregate 0s, 1s and 2s in sorted increasing order.
    void segragate012(int arr[], int n) {
        int zero = 0, one = 0, two = 0;
        for(int i = 0 ; i < n ; i++) {
            if(arr[i] == 0) zero++;
            else if(arr[i] == 1) one++;
            else if(arr[i] == 2) two++;
        }
        for(int i = 0 ; i < zero ; i++) arr[i] = 0;
        for(int i = zero ; i < zero + one; i++) arr[i] = 1;
        for(int i = zero + one ; i < zero + one + two; i++) arr[i] = 2;
    }
};

// { Driver Code Starts.
int main() {

    int T;
    cin >> T;

    while(T--){
        int N;
        cin >>N;
        int A[N];
        for(int i=0;i<N;i++){
            cin >> A[i];
        }

        Solution ob;
        ob.segragate012(A, N);

        for(int i=0;i<N;i++){
            cout << A[i]  << " ";
        }

        cout << endl;
        
        
    }

}
  // } Driver Code Ends