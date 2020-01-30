#include<bits/stdc++.h>
using namespace std;

int get_max_loot(int *arr, int i, int n,int* output){
    if(i >= n){
        return 0;
    }
    if(output[i] > -1){
        return output[i];
    }
    int ans1 = arr[i] + get_max_loot(arr, i+2, n, output);
    int ans2 = get_max_loot(arr, i+1, n, output);
    output[i] = max(ans1, ans2);
    return max(ans1, ans2);
}

int getMaxMoney(int arr[], int n){
    if(n == 1){
        return arr[0];
    }
    int *output = new int[n];
    for(int i=0; i < n;i++)
        output[i] = -1;
    int ans =  get_max_loot(arr, 0, n, output);
    return ans;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i < n; i++)
        cin >> arr[i];

    cout << getMaxMoney(arr, n) << endl;    
    return 0;
}