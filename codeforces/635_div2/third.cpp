/*
 
There are n cities and n−1 two-way roads connecting pairs of cities in the kingdom. From any city, you can reach any other city by walking through some roads. The cities are numbered from 1 to n, and the city 1 is the capital of the kingdom. So, the kingdom has a tree structure.

As the queen, Linova plans to choose exactly k cities developing industry, while the other cities will develop tourism. The capital also can be either industrial or tourism city.

A meeting is held in the capital once a year. To attend the meeting, each industry city sends an envoy. All envoys will follow the shortest path from the departure city to the capital (which is unique).

Traveling in tourism cities is pleasant. For each envoy, his happiness is equal to the number of tourism cities on his path.

In order to be a queen loved by people, Linova wants to choose k cities which can maximize the sum of happinesses of all envoys. Can you calculate the maximum sum for her?

Input
The first line contains two integers n and k (2≤n≤2⋅105, 1≤k<n)  — the number of cities and industry cities respectively.

Each of the next n−1 lines contains two integers u and v (1≤u,v≤n), denoting there is a road connecting city u and city v.

It is guaranteed that from any city, you can reach any other city by the roads.

Output
Print the only line containing a single integer  — the maximum possible sum of happinesses of all envoys.
*/


#include <bits/stdc++.h>
#define maxn 200005
std::vector<int>conj[maxn];	
int n,k,u,v,depth[maxn]={0},size[maxn]={0},det[maxn];
long long ans=0;
int cmp(int a,int b){return a>b;}
int dfs(int u,int f){depth[u]=depth[f]+1;size[u]=1;
	for (int i=0;i<conj[u].size();++i){
		if ((v=conj[u][i])==f)continue;
		size[u]+=dfs(v,u);
	}det[u]=size[u]-depth[u];return size[u];
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;++i){
		scanf("%d%d",&u,&v);conj[u].push_back(v);conj[v].push_back(u);
	}dfs(1,0);
	std::nth_element(det+1,det+n-k,det+n+1,cmp);
	for (int i=1;i<=n-k;++i)ans+=det[i];std::cout<<ans;
	return 0;
}