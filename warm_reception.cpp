#include<bits/stdc++.h>																																							
using namespace std;
int main(){																																					
	
	vector<int> time(2400);
	int n;
	cin>>n;
	int arrival[n],departure[n];
	
	for(int i=0;i<n;i++)
		cin>>arrival[i];
	
	for(int i=0;i<n;i++)
		cin>>departure[i];


	for(int i=0;i<n;i++){
		for(int j=arrival[i]; j <= departure[i]; j++){
			time[j]++;
		}
	}
	int max_chairs = -1;
	for(int i=0;i<time.size(); i++){
		max_chairs = max(max_chairs, time[i]);
	}
	cout<<endl;
	cout<<max_chairs;	
	return 0;				

}																																		
