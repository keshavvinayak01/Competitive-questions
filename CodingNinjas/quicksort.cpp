#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int start, int end){
	int pivot = a[end];
	int j = start - 1;
	for(int i = start ; i <= end; i++){
		if(a[i] < pivot){
			j++;
			swap(a[i], a[j]);
		}
	}
	swap(a[j+1], a[end]);
	return j+1;
}



void quick_sort(int a[], int start, int end){
	if(end > start){
		int c = partition(a,start,end);
		quick_sort(a, start, c-1); 
		quick_sort(a, c+1, end);
	}
	else return;
}


int main(){
	int n;
	cin>>n;
	int a[n];
	
	for(int i=0; i < n; i++)
		cin>>a[i];
	
	quick_sort(a,0,n-1);
	
	for(int i=0; i< n;i++)
		cout<<a[i]<<" ";
	
	cout<<endl;
	return 0;
}
// c = partition()
// qs(start,c-1)
// qs(c,end)