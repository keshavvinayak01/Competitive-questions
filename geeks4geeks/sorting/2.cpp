/*
Given an array A[] of n positive integers which can contain integers from 1 to P where elements can be repeated 
or can be absent from the array. Your task is to count the frequency of all elements from 1 to n.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
   bool find3Numbers(int arr[], int n, int X) {
    // First sort the array
    sort(arr, arr + n);
    int sum2, f, b;
    for(int i = 0 ; i < n-1 ; i++) {
        f = i+1;
        b = n-1;
        while(b > f) {
            sum2 = arr[i] + arr[f] + arr[b];
            
            if(sum2 > X) 
                b--;
            
            else if(sum2 < X)
                f++;
            else if(sum2 == X)
                return 1;
            }
        }       
    return 0;
    //Your Code Here
}

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends