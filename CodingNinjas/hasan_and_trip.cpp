#include <bits/stdc++.h>
using namespace std;

double dp[3000][3000];

double calc(int a[],int b[]){
    return (double)b[2]-(double)sqrt(pow((a[0]-b[0]),2)+pow((a[1]-b[1]),2));
}

double calculation(int arr[][3],int init,int curr,int e){
    if(curr==e){
        dp[curr][init]=calc(arr[init],arr[curr]);
        return dp[curr][init];
    }
    
    if(dp[curr][init]>0) return dp[curr][init];
    
    double exc=calculation(arr,init,curr+1,e);
    double inc=calc(arr[init],arr[curr])+calculation(arr,curr,curr+1,e);
    dp[curr][init]=max(exc,inc);
    return dp[curr][init];
}

int main(){
    int n;
    cin>>n;
    int arr[n][3];
    for(int i=0; i<n; i++) cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    
    //initial index,current index,terminating index
    printf("%.6f",((double)arr[0][2]+calculation(arr,0,1,n-1)));
    return 0;
}