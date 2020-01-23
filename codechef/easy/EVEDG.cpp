#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
     int t;
     cin>>t;

     while(t--){
         int n,m;
         cin>>n>>m;
         int arr[n+1];
         vector<int> mp[n+1];
         for(int i=0;i<=n;i++)
         arr[i]=0;
         for(int i=0;i<m;i++){
             int u,v;
             cin>>u>>v;
             arr[u]++;
             arr[v]++;
             mp[u].push_back(v);
             mp[v].push_back(u);
         }
         if(m%2==0){
             cout<<1<<endl;
             for(int i=1;i<=n;i++)
             cout<<1<<" ";
             cout<<endl;
         }
         else{
             int f = -1;
             for(int i=1;i<=n;i++){
                 if(arr[i]%2!=0){
                     f=i;
                     break;
                 }
             }
             if(f==-1){
                 cout<<3<<endl;
                 int pnt = -1;
                 for(int i=1;i<=n;i++){
                     if(arr[i]%2==0 && arr[i]!=0 && pnt==-1){
                         cout<<2<<" ";
                         int k=0;
                         while(i>mp[i][k])
                            k++;
                        pnt = mp[i][k];
                     }
                     else if(pnt==i){
                         cout<<3<<" ";
                     }
                     else{
                         cout<<1<<" ";
                     }
                 }
                 
             }
             else{
                 cout<<2<<endl;
                 for(int i=1;i<f;i++)
                    cout<<1<<" ";
                 cout<<2<<" ";
                 for(int i=f+1;i<=n;i++)
                    cout<<1<<" ";
                 cout<<endl;
             }
         }
     }
 }