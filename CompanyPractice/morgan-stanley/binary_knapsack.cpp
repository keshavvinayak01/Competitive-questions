#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;cin>>t;
  while(t--){
        int n,wt;
        cin >> n >> wt;
        int v[n],w[n];
        for(int i=0 ; i<n ; i++) cin >> v[i];

        for(int i=0 ; i<n ; i++) cin >> w[i];

        int k[wt+1];
        memset(k, 0, sizeof(k));
        for(int i = 0; i < n ; ++i)
        for(int j = wt; j > 0 ; --j)
        if(w[i] <= j)
            k[j] = max(k[j], v[i] + k[j - w[i]]);
        cout << k[wt] << endl;    
  }
	return 0;
}