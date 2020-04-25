#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

int getSum(int BITree[], int index) { 
    int sum = 0; // Initialize result 
  
    index = index + 1; 
  
    while (index>0) 
    { 
        sum += BITree[index]; 
  
        index -= index & (-index); 
    } 
    return sum; 
} 
  
void updateBIT(int BITree[], int n, int index, int val) 
{ 
    index = index + 1; 
  
    while (index <= n) 
    { 
        BITree[index] += val; 
  
        index += index & (-index); 
    } 
} 
  
int sum(int x, int BITTree1[], int BITTree2[]) 
{ 
    return (getSum(BITTree1, x) * x) - getSum(BITTree2, x); 
} 
  
  
void updateRange(int BITTree1[], int BITTree2[], int n, 
                 int val, int l, int r) 
{ 
  
    updateBIT(BITTree1,n,l,val); 
    updateBIT(BITTree1,n,r+1,-val); 
  
    updateBIT(BITTree2,n,l,val*(l-1)); 
    updateBIT(BITTree2,n,r+1,-val*r); 
} 
  
int rangeSum(int l, int r, int BITTree1[], int BITTree2[]) 
{ 
    return sum(r, BITTree1, BITTree2) - 
           sum(l-1, BITTree1, BITTree2); 
} 
  
  
int *constructBITree(int n) 
{ 
    int *BITree = new int[n+1]; 
    for (int i=1; i<=n; i++) 
        BITree[i] = 0; 
  
    return BITree; 
} 

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n, k, mid, ans, cur;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        int arr[n], sums[n/2];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        pair<int, int> cutoffs[n/2];
        for(int i = 0 ; i < n/2 ; i++) {
            cutoffs[i] = {
                min(arr[i], arr[n - i - 1]) + 1,
                max(arr[i], arr[n - i - 1]) + k
            };
        }     
        int *BITTree1, *BITTree2; 
        BITTree1 = constructBITree(2*k + 1); 
    
        BITTree2 = constructBITree(2*k + 1); 
        for(int i = 0 ; i < n/2; i++) {
            updateRange(BITTree1, BITTree2 , 2*k + 1, 1, cutoffs[i].first, cutoffs[i].second); 
            updateRange(BITTree1, BITTree2 , 2*k + 1, 2, 1, cutoffs[i].first - 1); 
            updateRange(BITTree1, BITTree2 , 2*k + 1, 1, cutoffs[i].second + 1, 2*k); 
        }
        int min_ans = INT_MAX;
        for(int i = 1 ; i <= 2*k ; i++) {
            min_ans = min(min_ans, rangeSum(i , i, BITTree1, BITTree2));
        }
        cout << min_ans << endl;
    }

    return 0;
}