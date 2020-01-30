#include<bits/stdc++.h>
using namespace std;
int board[11][11];

bool isPossible(int *arr, int i, intj){
	if(arr[i + j] == -1)
		return true;
	if(arr[i] + j] != val)
		return false;
	return true;
}



int main(){
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		int arr[2*n];
		for(int i=0; i < 2*n; i++)
				arr[i] = -1;
		bool ans = true;
		while(q--){
			int i,j,val;
			cin>>i>>j>>val;
			if(!isPossible(arr,i,j,val)){
				ans = false;
				break;
			}
			if(arr[i] == -1) arr[i] = 0;
			arr[j] = arr[i] + val;
		}
		if(ans){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}

	}

	return 0;
}