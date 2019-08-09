#include<bits/stdc++.h>
using namespace std;


void FindTriplet(int arr[], int size, int x){
	sort(arr, arr+size);
	vector<vector<int>> result;
	for(int i=0;i < size- 2;i++){
		for(int j=i+1;j < size - 1;j++){
			for(int k=j+1; k< size;k++){
				if(i == j || i == k || j==k) continue;
				if(arr[i] + arr[j] + arr[k] == x){
					result.push_back({arr[i], arr[j], arr[k]});
				}
			}
		}
	}
	for(int it = 0; it <  result.size(); it++){
		cout<<result[it][0]<<" "<<result[it][1]<<" "<<result[it][2]<<endl;
	}
}


int main(){

	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int x;
	cin>>x;
	sort(a, a + n);
	for(int i=0;i < n; i++)
		cout<<a[i]<<endl;
	FindTriplet(a, n, x);	
	return 0;
}
