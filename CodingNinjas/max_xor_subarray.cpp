#include<bits/stdc++.h> 
#define BIT_SIZE 21 
#define MAX_SIZE 1000002 
using namespace std; 

struct trie { 
    int cnt; 
    trie *children[2];
    trie() { 
        cnt=0; 
        children[0]=NULL; 
        children[1]=NULL; 
    } 
}; 

trie *root; 
int A[MAX_SIZE]; 

void insert_trie(int val) { 
    trie *node = root, *newNode, temp; 
    int i = 0; 
    for(i = BIT_SIZE-1 ; i >= 0; i--) { 
        bool k = (1<<i) & val;
        if(node->children[k] == NULL) { 
            newNode = new trie; 
            newNode->cnt = 1; 
            node->children[k] = newNode; 
        } 
        else 
        (node->children[k]->cnt)++; 
        node=node->children[k]; }  
} 

long long int query(int val) { int i=BIT_SIZE-1; long long ans=0; trie *node=root; if(root==NULL) return 0; while(i>=0) { bool p=(1<<i)&val; if(node->children[1-p]!=NULL) { node=node->children[1-p]; ans=ans*2+1; } else { node=node->children[p]; ans*=2; } i--; } return ans; } int main() { int t=1, n, i, mxor; long long ans; while(t--) { cin>>n; root=new trie; ans=0; mxor=0; insert_trie(mxor); for(i=0;i<n;i++) { cin>>A[i]; mxor^=A[i]; ans=max(ans, query(mxor)); insert_trie(mxor); } cout<<ans<<"\n"; } }
