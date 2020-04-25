#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		string s, t;
		cin >> s >> t;
		int n = s.size();
		vector<int> lengths;
		int curlen = 0, fl = 0;
		ll ans = 0;
		for(int i = 0; i < n; i++){
			if(s[i] != t[i]){
				if(curlen > 0 && fl > 0)
					lengths.push_back(curlen), ans += curlen;
				curlen = 0;
				fl = 1;
				ans++;
				continue;
			}
			++curlen;
		}
		n = ans;
		sort(lengths.begin(), lengths.end(), greater<int>());
		for(ll i = 0; i < lengths.size(); i++){
			n -= lengths[i];
			ans = min(ans, (i + 2) * n);
		}
		cout << ans << endl;
	}
} 