#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> get_cum_sum(ll *arr, ll n){
	vector<ll> result(n);
	result[0] = arr[0];
	for(int i=1; i < n;i++){
		result[i] = result[i-1] + arr[i];
	}
	return result;
}


int main(){
	ll n,q;
	cin>>n;
	ll arr[n];
	for(ll i=0;i < n; i++)
		cin>>arr[i];
	vector<ll> sums = get_cum_sum(arr, n);
	cin>>q;
	for(ll i=0; i < q; i++){
		ll moneyz;
		cin>>moneyz;
		int momos = lower_bound(sums.begin(), sums.end(), moneyz) - sums.begin();
		if(momos == 0){
			if(sums[0] == moneyz){
				cout<<"1 0"<<endl;
			}
			else if(sums[0] > moneyz){
				cout<<0<<" "<<moneyz<<endl;
			}
		}
		else{
			if(moneyz < sums[momos]){
				cout<<momos<<" "<<moneyz - sums[momos - 1]<<endl;
			}
			else if(moneyz == sums[momos]){
				cout<<momos + 1<<" "<<0<<endl;	
			}
		}
	}

	return 0;
}