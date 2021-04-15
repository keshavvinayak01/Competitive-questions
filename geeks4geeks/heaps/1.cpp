/*
    There are given N ropes of different lengths, we need to connect these ropes into one rope. 
    The cost to connect two ropes is equal to sum of their lengths. The task is to connect the 
    ropes with minimum cost.
*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

typedef long long ll;

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    ll minCost(ll arr[], ll n) {
        priority_queue< ll, vector<ll>, greater<ll> > pq;
        for(int i = 0 ; i < n ; i++)
            pq.push(arr[i]);
        // Your code here
        ll a, b, cost = 0;
        while(!pq.empty()) {
            a = pq.top(); pq.pop();
            if(pq.empty()) break;
            b = pq.top(); pq.pop();
            pq.push(a + b);
            cost += a + b;
        }   
        return cost;
    }
};


// { Driver Code Starts.
long long minCost(long long arr[], long long n);
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends