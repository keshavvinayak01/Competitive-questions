#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check_valid(ll candies[], ll mid, int n, int students){
	int count = 0;
	for(int i = 0 ; i < n ; i++){
		if(candies[i] >= mid){
			count += candies[i]/mid;
		}
		if(count >= students){
			return true;
		}
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		ll candies[n];
		ll start = 1, end;
		for(int i=0; i < n; i++){
			cin>>candies[i];
			if(i == 0){
				end = candies[i];
			}
			if(candies[i] > end){
				end = candies[i];
			}
		}
		int ans;
		while(start <= end){
			ll mid = start + (end - start)/2 ;
			if(check_valid(candies, mid, n, k)) {
				ans = mid;
				start = mid + 1;
			}
			else{
				end = mid - 1;
			}
		}
		cout<<ans<<endl;

	}
	return 0;
}