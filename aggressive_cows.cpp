#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check_valid(ll distances[], ll mid, int n, int cows){
	int count = 1;
	ll start = distances[0];
	for(int i = 0 ; i < n ; i++){
		if(distances[i] - start >= mid){
			count++;
			start = distances[i];
		}
		if(count == cows){
			return true;
		}
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,c;
		cin>>n>>c;
		ll distances[n];
		for(int i=0; i < n; i++)
			cin>>distances[i];
		sort(distances, distances + n);
		ll start = 0;
		int ans;
		ll end = distances[n-1] - distances[0];
		while(start <= end){
			ll mid = start + (end - start)/2 ;
			if(check_valid(distances, mid, n, c)){
				ans = mid;
				start = mid + 1;
			}
			else{
				end = mid - 1;
			}
		}
		cout<<ans;

	}
	return 0;
}