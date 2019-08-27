#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){

    ll n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll curr;
    ll ans;
    while(curr < (n-1)){
        ll next = curr+1;
        while(next < n-1){
            if(abs(arr[curr] > abs(arr[next])) || ((abs(arr[curr]) == abs(arr[next])) && abs(arr[curr]) > 0)){
                break;
            } else{
                next++;
            }
        }
        ans += (next - curr)*arr[curr] + (next*next - curr*curr) - arr[curr]*arr[curr];
        curr = next;    
    }
    return 0;
}