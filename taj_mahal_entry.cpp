#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;
	int arr[n];
	for(int i=0 ; i < n ; i++)
		cin>>arr[i];

	int result[n];
	int t;
	for(int i=0 ; i<n ; i++){
		t = (arr[i] - i)/n ;
		if((arr[i] - i)%n > 0)
			t++;
		result[i] = i + t*n;
	}
	for(int i=0 ; i<n ; i++){
		if(i >= result[i] || arr[i] >= result[i]){
			cout<<(i+1)<<endl;
			break;
		}
	}
	return 0;
}