#include<bits/stdc++.h>
using namespace std;

struct Job{
    int start, finish, profit;
};

bool compare(Job a, Job b){
    return a.finish < b.finish;
}

int binarySearch(int start, int end, int max, Job arr[]){
    int ans = -1;
    while(start <= end){
			int mid = start + (end - start)/2 ;
			if(arr[mid].finish <= arr[max].start){
				ans = mid;
				start = mid + 1;
			}
			else{
				end = mid - 1;
			}
		}
    return ans;
}


int fMProfit(Job arr[], int n){
    sort(arr, arr+n, compare);
    int* dp = new int[n];
    dp[0] = arr[0].profit;

    for(int i=1; i < n; i++){
        int including = arr[i].profit;
        int lNConflict = binarySearch(0, i-1, i, arr);
        if(lNConflict != -1){
            including += dp[lNConflict];
        }
        dp[i] = max(including, dp[i-1]);
    }
    int ans = dp[n-1];
    delete[] dp;
    return ans;
}

int main(){
    int n;
    cin >> n;
    Job a[n];
    for(int i=0; i<n; i++){
        int start, finish, profit;
        cin >> start >> finish >> profit;
        a[i] = {start, finish, profit};
    }

    cout << fMProfit(a, n) << endl;
    return 0;
}