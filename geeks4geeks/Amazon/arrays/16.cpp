// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int *arr, int n){
        for(int i = 1 ; i < n ; i++) {
            if((arr[i-1] <= arr[i] && arr[i] <= arr[i+1]) || 
               (arr[i-1] >= arr[i] && arr[i] >= arr[i+1])) {
                   swap(arr[i], arr[i-1]);
                   i++;
               }
            if(i == n-1 && (arr[i] >= arr[i-1] && arr[i-1] >= arr[i-2]) || 
                           (arr[i] <= arr[i-1] && arr[i-1] <= arr[i-2]))
                    swap(arr[i], arr[i-1]);
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    cin>>t; //Input testcases
    while(t--) //While testcases exist
    {
        cin>>n; //input size of array
        int a[n]; //declare array of size n
        for(int i=0;i<n;i++)
            cin>>a[i]; //input elements of array
        Solution ob;
        ob.convertToWave(a, n);

        for(int i=0;i<n;i++)
            cout<<a[i]<<" "; //print array
            
        cout<<endl;
    }
}  // } Driver Code Ends