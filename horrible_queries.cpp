
#include<bits/stdc++.h>
using namespace std;
 
 
void helper(int* tree,int* lazy,int start,int end,int treenode){
    int n=(end-start+1);
    tree[treenode] += n*lazy[treenode];
    if(start!=end){
        lazy[2*treenode] += lazy[treenode];
        lazy[2*treenode+1] += lazy[treenode];
      }
    lazy[treenode] = 0;
    return;
}
 
void build(int* arr,int* tree,int start,int end,int treenode){
 
  if(start==end){
    tree[treenode] = arr[start];
    return;
  }
 
  int mid=(start+end)/2;
  build(arr,tree,start,mid,2*treenode);
  build(arr,tree,mid+1,end,2*treenode+1);
  tree[treenode] = tree[2*treenode] + tree[2*treenode+1];
}
 
void update(int* arr,int* tree,int* lazy,int start,int end,int treenode,int left,int right,int value){
 
  if(lazy[treenode] != 0){
    helper(tree,lazy,start,end,treenode);
  }
 
  if(right<start || left>end){
    return;
  }
 
  if(start>=left && end<=right){
      int n=(end-start+1);
      tree[treenode] += value;
      if(start!=end){
          lazy[2*treenode] += value;
          lazy[2*treenode+1] += value;
        }
    return;
    }
  int mid=(start+end)/2;
  update(arr ,tree ,lazy ,start ,mid ,2*treenode ,left ,right ,value);
  update(arr ,tree ,lazy ,mid+1 ,end ,2*treenode+1 ,left ,right ,value);
  tree[treenode] = tree[2*treenode] + tree[2*treenode+1];
  return;
}
 
int query(int* tree, int* lazy, int start, int end, int treenode, int left, int right){
 
  if((lazy[treenode].cat)!=INT_MIN){
    helper(tree,lazy,start,end,treenode);
  }
 
  if(right<start || left>end){
    node temp;
    temp.square=0;
    temp.sum=0;
    return temp;
  }
 
  if(start>=left && end<=right){
    return tree[treenode];
  }
 
  int mid=(start+end)/2;
  node ans1=query(tree,lazy,start,mid,2*treenode,left,right);
  node ans2=query(tree,lazy,mid+1,end,2*treenode+1,left,right);
  node ans;
  ans.sum=ans1.sum+ans2.sum;
  ans.square=ans1.square+ans2.square;
  return ans;
 
}
 
int main() {
 
  int t;
  cin>>t;
  int num=0;
  while(t--){
 
    int n,q;
    cin>>n>>q;
 
    int* arr=new int[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
 
    node* tree=new node[4*n];
    build(arr,tree,0,n-1,1);
 
    alter* lazy=new alter[4*n];
    for(int i=0;i<4*n;i++){
      lazy[i].cat=INT_MIN;
      lazy[i].x=0;
    }
 
    num++;
    int flag=0;
    while(q--){
 
      int type,left,right;
      cin>>type>>left>>right;
      if(type==2){
        if(flag==0){
          cout<<"Case "<<num<<":\n";
        }
        flag=1;
        node ans=query(tree,lazy,0,n-1,1,left-1,right-1);
        cout<<ans.square<<"\n";
      }
      else if(type==1){
        int x;
        cin>>x;
        update(arr,tree,lazy,0,n-1,1,left-1,right-1,x,type);
      }
      else if(type==0){
        int x;
        cin>>x;
        update(arr,tree,lazy,0,n-1,1,left-1,right-1,x,type);
      }
    }
 
    delete [] arr;
    delete [] tree;
    delete [] lazy;
  }
}