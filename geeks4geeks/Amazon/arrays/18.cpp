// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>&, int );


int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        
        vec = productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}// } Driver Code Ends


vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
    if(n == 1) {
        vector<long long int> randomResult(1);
        randomResult[0] = 1;
        return randomResult;
    }
    long long int left[n], right[n];
    left[0] = nums[0];
    right[n-1] = nums[n-1];
    for(int i = 1 ; i < n ; i++) {
        left[i] = nums[i]*left[i-1];
    }
    for(int i = n-2 ; i >= 0 ; i--) {
        right[i] = nums[i]*right[i+1];
    }
    vector<long long int> result(n);
    result[0] = right[1];
    result[n-1] = left[n-2];
    for(int i = 1 ; i < n - 1; i++) {
        result[i] = left[i-1] * right[i+1];
    }
    return result;
}
