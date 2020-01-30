#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll merge(int a[], int left, int mid, int right){
	int i=left, j = mid, k=0;
	ll count = 0;
	bool repeat = false;
	int temp[right - left + 1]; 	
	while(i < mid && j <= right){
		repeat = false;
		if(a[i] < a[j]){
			count += (right - j + 1)*a[i];				
			temp[k++] = a[i++];
		}
		else{
			temp[k++] = a[j++];
		}
	}
	while(i < mid) temp[k++] = a[i++];
	while(j <= right) temp[k++] = a[j++];

	for(int i = left,k=0; i<=right;i++,k++)
		a[i] = temp[k];
	return count;
}

ll merge_sort(int a[], int left, int right){
	ll count = 0;
	if(right > left){
		int mid = (left + right)/2 ;
		ll countLeft = merge_sort(a, left, mid);
		ll countRight = merge_sort(a, mid+1, right);		
		ll myCount = merge(a, left, mid+1, right);
		return myCount + countLeft + countRight;
	}
	return count;
}


ll solve(int a[], int n){
	ll ans = merge_sort(a, 0 , n-1);
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
	
		int n;
		cin>>n;
		int arr[n];
		for(int i=0 ; i < n ; i++)
			cin>>arr[i];
		// cout<<endl;	
		cout<<solve(arr, n)<<endl;
	
	}
	
	return 0;
}