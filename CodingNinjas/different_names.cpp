#include<bits/stdc++.h>
using namespace std;

int main(){
	map<string,int> name_counts;
	string input;
	getline(cin, input);
	
	istringstream s(input);
	while(s){
		string word;
		s >> word;
		name_counts[word] = name_counts[word] + 1; 
	}
	map<string,int>::iterator it;
	int i;
	for(it = name_counts.begin(); it != name_counts.end(); it++){
		if(it->second > 1){
			cout<<it->first<<" "<<it->second<<endl;
		}
		else{
			i++;
		}
	}
	if(i == name_counts.size()){
		cout<<"-1";
	}
	return 0;
}