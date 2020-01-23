#include<bits/stdc++.h>
#define MOD 1000000007
typedef long long int lli;
using namespace std;

struct node {
    lli vertex;
    lli weight;
    vector<int> edge_list;
    node() {
        vertex = weight = -1;
    }
};

lli getSize(int start, int end, vector<vector<int>> edges, bool visited[], int weight[]) {
    if(start == end) return weight[end] % MOD;

    visited[start] = true;
    for(int i = 0 ; i < edges[start].size(); i++) {
        int next = edges[start][i];
        if(!visited[next]) {
            cout << start << " " << next << " " << weight[start] + weight[next] <<  endl;
            return (weight[start] % MOD + getSize(next, end, edges, visited, weight) % MOD) % MOD;
        }
    }
}

bool sortMax(node a, node b) {
    return a.edge_list.size() < b.edge_list.size();
}

lli getMaxProfit(vector<node> edges, lli arr[], int n) {
    sort(arr, arr+n);

    int weight[n];
    vector<vector<int>> edge_list(n);
    for(int i = 0 ; i < n; i++) edge_list[i] = edges[i].edge_list;

    sort(edges.begin(), edges.end(), sortMax); 
    for(int i = 0 ; i < n ; i++) {
        weight[edges[i].vertex] = arr[i];
    }
    
    vector<int> leaves;
    for(int i = 0 ; i < n ; i++) {
        if(edge_list[i].size() == 1) leaves.push_back(i);
    }
    cout << endl;
    lli ans = 0;
    bool visited[n];
    for(int i = 0 ; i < n ; i++) visited[i] = false;
    for(int i = 0 ; i < leaves.size()-1; i++) {
        for(int j = i+1; j < leaves.size(); j++) {
            cout << "from: " << leaves[i] << " to " << leaves[j] << endl; 
            for(int i = 0 ; i < n ; i++) visited[i] = false;

            ans += getSize(leaves[i], leaves[j], edge_list, visited, weight) % MOD;
            ans = ans % MOD;
        }
    }  
    return ans;
}

int main() {
    int t, a, b, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<node> edges(n);
        lli arr[n];
        for(int i =0 ; i < n ; i++){
            cin >> arr[i];
            edges[i].vertex = i;
            edges[i].weight = arr[i];
        }
        node nodes[n];
        for(int i = 0 ; i < n-1; i++) {
            cin >> a >> b;
            edges[a-1].edge_list.push_back(b-1);
            edges[b-1].edge_list.push_back(a-1);
        }
        cout << getMaxProfit(edges, arr, n) << endl;
    }

    return 0;
}