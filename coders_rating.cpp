#include<bits/stdc++.h>
using namespace std;

struct coder
{
	int x,y,index;
};
int bit[100001];

void update(int y){

	for(;y<=100000;y+= y&(-y)){
		bit[y]++;
	}
}

int query(int y){
	int value = 0;
	for(;y>0;y-= y&(-y)){
		value += bit[y];
	}
	return value;
}
bool operator < (coder A, coder B){
	if(A.x == B.x){
		return A.y < B.y;
	}
	return A.x < B.x;
}
int main(){

	int n;
	cin >> n;
	coder arr[n];

	for(int i=0;i<n;i++){
		cin>>arr[i].x >> arr[i].y;
		arr[i].index = i;
	}

	sort(arr,arr+n);
	int ans[n];
	for(int i=0;i<n;){
		int endIndex = i;

		while(endIndex <n && arr[endIndex].x == arr[i].x && arr[endIndex].y == arr[i].y){
			endIndex++;
		}
		// query

		for(int j=i;j<endIndex;j++){
			ans[arr[j].index] = query(arr[j].y);
		}

		for(int j=i;j<endIndex;j++){
			update(arr[j].y);
		}

		i = endIndex;
		
		// update
	}

	for(int i=0;i<n;i++){
		cout << ans[i] <<endl;
	}

	
	return 0;
}