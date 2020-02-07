#include<iostream>
using namespace std;
int main()
 {
	//code
	int t,i,ans,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int arr[n],left[n]={0},right[n]={0};
	    for(i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    left[0] = arr[0];
	    right[n-1] = arr[n-1];
	    // Compute left array that contains the largest element on the left of the current element
	    for(i=1;i<n;i++)
	    {
	        if(arr[i]>left[i-1])
	        {
	            left[i] = arr[i];
	        }
	        else
	        {
	            left[i] = left[i-1];
	        }
	    }
	    // Compute right array that contains the largest element on the right of the current element
	    for(i=n-2;i>=0;i--)
	    {
	        if(arr[i]>right[i+1])
	        {
	            right[i] = arr[i];
	        }
	        else
	        {
	            right[i] = right[i+1];
	        }
	    }
	    // Compute the result
	    // Each block can trap water equal to the min(left[i],right[i])-arr[i]
	    ans = 0;
	    for(i=1;i<n-1;i++)
	    {
	        ans = ans + (min(left[i],right[i])-arr[i]);
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}
