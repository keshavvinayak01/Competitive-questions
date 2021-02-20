// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll FindMaxSum(ll arr[], ll n) {
    int incl = arr[0], excl = 0;
    int excl_new;
    for(int i = 1 ; i < n ; i++) {
        excl_new = incl > excl ? incl : excl;
        incl = excl + arr[i];
        excl = excl_new;
    }
    return max(incl, excl);
}


int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		ll n;
		cin>>n;
		ll a[n];
		
		//inserting money of each house in the array
		for(ll i=0;i<n;++i)
			cin>>a[i];
			
		//calling function FindMaxSum()
		cout<<FindMaxSum(a,n)<<endl;
	}
	return 0;
}