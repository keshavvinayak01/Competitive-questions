#include<bits/stdc++.h>
using namespace std;

int compare(pair<int,int> x, pair<int,int> y){
	return x.first < y.first; 
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int arr[m];
		vector<pair<int,int>> times;
		for(int i=0; i <n;i++){
			int a,b;
			cin>>a>>b;
			times.push_back(make_pair(a,b));
		}
		for(int i=0; i < m; i++)
			cin>>arr[i];
		sort(times.begin(), times.end(), compare);
		vector<int> opening_times;
		vector<int> closing_times;
		for(int i=0 ; i < n ; i++){
			opening_times.push_back(times[i].first);
			closing_times.push_back(times[i].second);
		}

		int results[m];
		int calc_i;
		for(int i=0; i < m ; i++){
			calc_i = lower_bound(opening_times.begin(),opening_times.end(), arr[i]) - opening_times.begin();
			cout<<"array val : "<<arr[i]<<" "<<calc_i<<"range : "<<opening_times[calc_i]<<" "<<closing_times[calc_i]<<endl;
			if(closing_times[calc_i] - arr[i] < 0){
				results[i] = -1;
			}
			else if (calc_i == 0){
				results[i] = opening_tunes[0] - arr[i];
			}
			else if(arr[i] >= closing_times[calc_i - 1]){
				results[i] = opening_times[calc_i] - arr[i];
			}
			else if(arr[i] < closing_times[calc_i - 1]){
				results[i] = 0;
			}
		}
		for(int i = 0; i < m; i++)
			cout<<results[i]<<endl;
	}
	return 0;
}
