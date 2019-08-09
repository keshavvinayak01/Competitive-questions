#include<bits/stdc++.h>
using namespace std;


void PairSum(int *input, int n){
	map<int, int> counts;
	map<int, int> conjugates;
	for(int i=0; i < n; i++){
		counts[input[i]] = counts[input[i]] + 1;
		if(input[i] > 0)
			conjugates[input[i]] = (-1)*input[i];
	}
	if(conjugates.size() == 0){
		for(int i=0; i < n; i++){
			if(input[i] < 0)
				conjugates[input[i]] = (-1)*input[i];	
		}
	}
	map<int, int>::iterator it;
	map<int, int>::iterator it1;
	map<int, int>::iterator it2;
	vector<vector<int>> result;
	map<int, int>::iterator it4;
	for(it4 = conjugates.begin(); it4 != conjugates.end(); it4++){
		it1 = counts.find(it4->first);
		it2 = counts.find(it4->second);
		if(it1 != counts.end() && it2 != counts.end()){
			for(int i=0; i< (it1->second)*(it2->second); i++){
				cout<<it4->second<<" "<<it4->first<<endl;
			}
		}		

	}
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i< n; i++)
		cin>>a[i];
	PairSum(a, n);
}
