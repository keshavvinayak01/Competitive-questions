#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool PerformOperation(ll n, ll k){
	ll balls = 0;
	ll temp = n;
	while(temp > 0){	
		balls += min(temp, k);
		temp -= k;
		temp = temp - temp/10;
	}
	if(2*balls >= n){
		return true;
	}
	return false;
}


int main(){

	ll n;
	cin>>n;
	if(n == 1){
		cout << "1" << endl;
	}
	else {
		ll ans = n;
		ll start = 0;
		ll mid;
		ll end = n;
		while(start < end){
			mid = (start + end)/2;
			if(PerformOperation(n, mid)){
				ans = mid;
				end = mid - 1;
			}
			else{
				start = mid + 1;
			}
			// if(start == end) break; 
		}
		for(int i = ans; i >= 1; i--){
			if(!PerformOperation(n, i)){
				break;
			}
			else{
				ans = i;
			}
		}
		cout << ans <<endl;
	}
	return 0;
}