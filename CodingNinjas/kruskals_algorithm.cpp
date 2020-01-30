#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int src, dest, weight;
};
bool compare(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

int getParent(int* parent, int v) {
    if(parent[v] == v) return  v;
    return getParent(parent, parent[v]);
}

Edge* kruskals(Edge* edges, int n, int E) {
    sort(edges, edges + n, compare);

    Edge* output = new Edge[n-1];

    int* parent = new int[n];
    for(int i = 0 ; i < n ; i++) parent[i] = i;

    int count = 0;
    int i = 0;
    while(count < n-1){
        Edge currentEdge = edges[i];
        int srcParent = getParent(parent, currentEdge.src);
        int destParent = getParent(parent, currentEdge.dest);
        if(srcParent != destParent) {
            output[count] = currentEdge;
            count++;
            parent[srcParent] = parent[destParent];
        }
        i++;
    }
    return output;
}

int main(){
    int n, E;
    cin >> n >> E;
    Edge* edges = new Edge[E];

    for(int i = 0; i < E; i++){
        int s, d, w;
        cin >> s >> d >> w;
        edges[i].src = s;
        edges[i].dest = d;
        edges[i].weight = w;
    }

    Edge* output = kruskals(edges, n, E);
    for(int i = 0 ; i< n-1; i++){
        if(output[i].src < output[i].dest) {
            cout << output[i].src << " " << output[i].dest << " " << output[i].weight << endl;
        }
        else {
            cout << output[i].dest << " " << output[i].src << " " << output[i].weight << endl;
        }
        
    }
    return 0;
}