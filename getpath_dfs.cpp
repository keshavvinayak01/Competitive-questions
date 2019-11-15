#include<bits/stdc++.h>
using namespace std;

int printDFS(int **graph,int n,int s,int e,bool* visited,vector<int>&v){
    visited[s]=true;
    if(s==e)
    {
        return 1;
    }
    for(int i=0;i<n;i++){
        if(i==s){
            continue;
        }
        if(graph[s][i]==1){
            
            if(visited[i]){
                continue;
            }
            if(printDFS(graph,n,i,e,visited,v)){
                v.push_back(s);
                return 1;
            }
        } 
    }
    return 0;
}

int main()
{
  int n,e;
    cin >>n>>e;
    int **graph=new int*[n];
    for(int i=0;i<n;i++){
        graph[i]=new int[n];
        for(int j=0;j<n;j++){
            graph[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    int v1,v2;
    cin>>v1>>v2;
    bool *visited=new bool[n];
    for(int i=0;i<n-1;i++){
        visited[i]=false;
    }
    vector<int> v;
    int p=printDFS(graph,n,v1,v2,visited,v);
    if(p)
    cout<<v2<<" ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    for(int i=0;i<n;i++){
        delete[] graph[i];
    }
    delete[] graph;
  return 0;
}