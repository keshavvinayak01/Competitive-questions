#include<bits/stdc++.h>
using namespace std;

vector<int> longestSubsequence(int *arr, int n){
	// Write your code here
    map<int, int> indices;
    for(int i=0;i<n;i++){
        indices[arr[i]] = i;
    }
    sort(arr, arr+n);
    vector<int> longest_till_now = {arr[0]};
    vector<int> longest_total;
    
    for(int i=0 ; i < n - 1 ; i++){
        if(arr[i+1] == arr[i]){
            continue;
        }
        if(arr[i+1] - arr[i] == 1){
            // cout<<arr[i+1]<<" ";
            // longest_till_now.push_back(arr[i]);
            longest_till_now.push_back(arr[i+1]);
        }         
        else{
            if(longest_till_now.size() > longest_total.size()){
                longest_total = longest_till_now;
            }
            else if(longest_till_now.size() == longest_total.size()){
                if(indices[longest_till_now[0]] < indices[longest_total[0]])
                    longest_total = longest_till_now;
            }

            longest_till_now.clear(); 
            longest_till_now = {arr[i+1]};
        }
    }
    if(longest_till_now.size() > longest_total.size())
        longest_total = longest_till_now;
    return longest_total;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ;i < n; i++)
        cin>>arr[i];
    vector<int> result = longestSubsequence(arr, n);
    for(int i=0; i < result.size(); i++)
        cout<<result[i]<<endl;
    cout<<endl;
    return 0;
}