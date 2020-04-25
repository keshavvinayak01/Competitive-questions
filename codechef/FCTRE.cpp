#include<bits/stdc++.h>
typedef unsigned long long int lli;
#define MOD 1000000007
using namespace std;

void SieveOfEratosthenes(lli largest, vector<lli> &prime) { 
    bool isPrime[largest+1]; 
    memset(isPrime, true, sizeof(isPrime)); 
  
    for (int p=2; p*p<=largest; p++) { 
        if (isPrime[p] == true) { 
            for (int i=p*2; i<=largest; i += p) 
                isPrime[i] = false; 
        } 
    } 
  
    for (lli p=2; p<=largest; p++) 
        if (isPrime[p]) 
            prime.push_back(p); 
} 
  
lli countDivisorsMult(vector<int> path, lli costs[], vector<lli> prime) {
    int n = path.size();
    lli arr[n];
    for(int i = 0; i < n ; i++) arr[i] = costs[path[i]];
    for(int i = 0 ; i < n ; i++) cout << arr[i] << " ";
    cout << endl;
    unordered_map<int, int> mp; 
    for (int i=0; i<n; i++) { 
        for (int j=0; j<prime.size(); j++) { 
            while(arr[i] > 1 && arr[i]%prime[j] ==0 ) { 
                arr[i] /= prime[j]; 
                mp[prime[j]]++; 
            } 
            if(arr[i] == 0) break;
        } 
        if (arr[i] != 1) 
            mp[arr[i]]++; 
    } 
  
    lli res = 1; 
    for (auto it : mp) 
       res = ((res % MOD) * ((it.second + 1L) % MOD)) % MOD; 
    return res; 
} 

int computePathHelper(int start, int end, vector<vector<int>> edge_list, vector<int>&stack, bool* visited) {
    visited[start] = true;
    if(start == end) return 1;
    for(int i = 0 ; i < edge_list[start].size(); i++) {
        int curr = edge_list[start][i];
        if(!visited[curr]) {
            if(computePathHelper(curr, end, edge_list, stack, visited)) {
                stack.push_back(start);
                return 1;
            }
        }
    }
    return 0;
}

vector<int> computePath(int start, int end, vector<vector<int>> edge_list, int n, bool* visited) {
    memset(visited, false, sizeof(visited));
    vector<int> ans, real_ans;
    computePathHelper(start, end, edge_list, ans, visited);
    for(int i = ans.size()-1 ; i >= 0 ; i--) {
        real_ans.push_back(ans[i]);
    }
    real_ans.push_back(end);
    return real_ans;
}

int bekaarPrime(vector<int> ans, lli costs[], vector<lli> prime) {
    lli a = 1;
    for(int i = 0 ; i < ans.size(); i++) {
        a *= costs[ans[i]];
    }
    unordered_map<int, int> mp; 
    for (int j=0; j<prime.size(); j++) { 
        while(a > 1 && a % prime[j] ==0 ) { 
            a /= prime[j]; 
            mp[prime[j]]++; 
        } 
        if(a == 0) break;
    } 
    if (a != 1) 
        mp[a]++; 
    lli res = 1; 
    for (auto it : mp) {
        res = ((res % MOD) * ((it.second + 1L) % MOD)) % MOD; 
    } 
    return res; 
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    vector<lli> prime; 
    SieveOfEratosthenes(1000000L, prime);
    int t, a, b, q, n;
    vector<int> ans;
    cin >> t;
    while(t--) {
        cin >> n;
        bool visited[n];
        vector<vector<int>> edge_list(n);
        for(int i = 0 ; i < n-1; i++) {
            cin >> a >> b;
            a--; b--;
            edge_list[a].push_back(b);
            edge_list[b].push_back(a);
        }
        lli costs[n];
        for(int i = 0 ; i < n ; i++) cin >> costs[i];
        cin >> q;
        while(q--) {
            cin >> a >> b;
            ans = computePath(a-1, b-1, edge_list, n, visited);
            // c// cout << endl;
            cout << bekaarPrime(ans, costs, prime) << endl;
        }
    }

    return 0;
}