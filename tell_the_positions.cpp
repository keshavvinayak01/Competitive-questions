#include<bits/stdc++.h>
using namespace std;

struct StudentPair{
	int roll_number;
	string name;
	int total_marks;
};

bool compare(StudentPair a1, StudentPair a2){
	if((a1.total_marks > a2.total_marks) || (a1.total_marks < a2.total_marks)){
		return a1.total_marks > a2.total_marks;
	}
	else if(a1.total_marks == a2.total_marks)
	return a1.roll_number < a2.roll_number;
}

int main(){

	int n;
	cin>>n;
	int roll_number = 0;
	vector<StudentPair> marks;
	while(n--){
		string s;
		int temp[3];
		cin>>s>>temp[0]>>temp[1]>>temp[2];
		marks.push_back({roll_number++, s, temp[0] + temp[1] + temp[2]});
	}

	sort(marks.begin() , marks.end(), compare);
	vector<StudentPair>::iterator it;
	int i=1;
	for(int it= 0; it < marks.size() ; it++){
		cout<<i++<<" "<<marks[it].name<<endl;
	}

	return 0;
}