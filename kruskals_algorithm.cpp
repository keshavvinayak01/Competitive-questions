#include<bits/stdc++.h>
using namespace std;

struct edge{
    int a, b, weight;
};

void findMST(edge* inputs, int* parent, vector<edge> outputs, int v, int e) {
    int count = 0;
    for(int i = 0; i < e; i++){
        if(count >= e-1) break;
        if(parent[inputs[i].a] != parent[inputs[i].b]){
            // cout << "parents : ";
            // for(int i = 0 ; i < e; i++) cout << parent[i] << " ";
            // cout << endl;
            if(inputs[i].a > inputs[i].b) {
                int temp = inputs[i].a;
                inputs[i].a = inputs[i].b;
                inputs[i].b = temp;
            }
            outputs.push_back(inputs[i]);
            count++;
            parent[inputs[i].a] = parent[parent[inputs[i].a]];
            parent[inputs[i].b] = parent[inputs[i].a];
        }
    }
    for(int i = 0; i < outputs.size(); i++){
        cout << outputs[i].a << " " << outputs[i].b << " " << outputs[i].weight << endl;
    }
}

bool cmpEdge(edge a, edge b){
    return a.weight < b.weight;
}

int main(){
    int v, e;
    cin >> v >> e;
    edge inputs[e];
    int parent[v];
    vector<edge> outputs;
    
    for(int i = 0 ; i < v; i++) parent[i] = i;

    for(int i = 0; i < e; i++) cin >> inputs[i].a >> inputs[i].b >> inputs[i].weight;
    
    sort(inputs, inputs + e, cmpEdge);
    
    findMST(inputs, parent, outputs, v, e);
    return 0;
}