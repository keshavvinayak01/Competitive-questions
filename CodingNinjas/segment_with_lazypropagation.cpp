
#include<bits/stdc++.h>
using namespace std;
 
struct node{  
 
  int64_t sum;
  int64_t square;
 
  node(){
    sum=square=0;
  }
 
};
 
struct alter{
 
  int64_t cat;
  int64_t x;
 
  alter(){
    cat=INT_MIN;
    x=0;
  }
};
 
void helper(node* tree,alter* lazy,int start,int end,int treenode){
 
  if(lazy[treenode].cat==1){
    int n=(end-start+1);
    (tree[treenode].square)+=n*((lazy[treenode].x)*(lazy[treenode].x)) + 2*(lazy[treenode].x)*(tree[treenode].sum);
    (tree[treenode].sum)+=n*lazy[treenode].x;
    if(start!=end){
      if(lazy[2*treenode].cat==0){
        lazy[2*treenode].x+=lazy[treenode].x;
      }
      if(lazy[2*treenode+1].cat==0){
        lazy[2*treenode+1].x+=lazy[treenode].x;
      }
      if(lazy[2*treenode].cat==0 && lazy[2*treenode + 1].cat!=0){
        lazy[2*treenode+1].cat=1;
        lazy[2*treenode+1].x+=lazy[treenode].x;
      }
      if(lazy[2*treenode].cat!=0 && lazy[2*treenode+1].cat==0){
        lazy[2*treenode].cat=1;
        lazy[2*treenode].x+=lazy[treenode].x;
      }
      if(lazy[2*treenode].cat!=0 && lazy[2*treenode+1].cat!=0){
      	lazy[2*treenode].cat=1;
      	lazy[2*treenode+1].cat=1;
      	lazy[2*treenode].x+=lazy[treenode].x;
      	lazy[2*treenode+1].x+=lazy[treenode].x;
      }
    }
 
    lazy[treenode].cat=INT_MIN;
    lazy[treenode].x=0;
  }
  else if(lazy[treenode].cat==0){
    int n=(end-start+1);
    (tree[treenode].square)=n*((lazy[treenode].x)*(lazy[treenode].x));
    (tree[treenode].sum)=n*(lazy[treenode].x);
    if(start!=end){
      lazy[2*treenode].cat=0;
      lazy[2*treenode+1].cat=0;
      lazy[2*treenode].x=lazy[treenode].x;
      lazy[2*treenode+1].x=lazy[treenode].x;
    }
    lazy[treenode].cat=INT_MIN;
    lazy[treenode].x=0;
  }
 
  return;
}
 
void build(int* arr,node* tree,int start,int end,int treenode){
 
  if(start==end){
    tree[treenode].sum=arr[start];
    tree[treenode].square=arr[start]*arr[start];
    return;
  }
 
  int mid=(start+end)/2;
  build(arr,tree,start,mid,2*treenode);
  build(arr,tree,mid+1,end,2*treenode+1);
  tree[treenode].square=tree[2*treenode].square + tree[2*treenode+1].square;
  tree[treenode].sum=tree[2*treenode].sum + tree[2*treenode+1].sum;
}
 
void update(int* arr,node* tree,alter* lazy,int start,int end,int treenode,int left,int right,int value,int type){
 
  if((lazy[treenode].cat)!=INT_MIN){
    helper(tree,lazy,start,end,treenode);
  }
 
  if(right<start || left>end){
    return;
  }
 
  if(start>=left && end<=right){
    if(type==1){
      int n=(end-start+1);
      (tree[treenode].square)+=n*(value*value) + 2*(value)*(tree[treenode].sum);
      (tree[treenode].sum)+=n*value;
      if(start!=end){
        if(lazy[2*treenode].cat==0){
          lazy[2*treenode].x+=value;
        }
        if(lazy[2*treenode+1].cat==0){
          lazy[2*treenode+1].x+=value;
        }
        if(lazy[2*treenode].cat!=0 && lazy[2*treenode+1].cat==0){
          lazy[2*treenode].x+=value;
          lazy[2*treenode].cat=1;
        }
        if(lazy[2*treenode].cat==0 && lazy[2*treenode+1].cat!=0){
          lazy[2*treenode+1].cat=1;
          lazy[2*treenode+1].x+=value;
        }
        if(lazy[2*treenode].cat!=0 && lazy[2*treenode+1].cat!=0){
          lazy[2*treenode].cat=1;
          lazy[2*treenode+1].cat=1;
          lazy[2*treenode].x+=value;
          lazy[2*treenode+1].x+=value;
        }
      }
    }
    else if(type==0){
      int n=(end-start+1);
      (tree[treenode].square)=n*(value*value);
      (tree[treenode].sum)=n*value;
      if(start!=end){
        lazy[2*treenode].cat=0;
        lazy[2*treenode+1].cat=0;
        lazy[2*treenode].x=value;
        lazy[2*treenode+1].x=value;
      }
    }
    return;
  }
 
  int mid=(start+end)/2;
  update(arr,tree,lazy,start,mid,2*treenode,left,right,value,type);
  update(arr,tree,lazy,mid+1,end,2*treenode+1,left,right,value,type);
  tree[treenode].sum=tree[2*treenode].sum + tree[2*treenode+1].sum;
  tree[treenode].square=tree[2*treenode].square + tree[2*treenode+1].square;
  return;
}
 
node query(node* tree,alter* lazy,int start,int end,int treenode,int left,int right){
 
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