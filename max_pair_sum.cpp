#include<bits/stdc++.h>
using namespace std;

int curr_idx = -1;

struct node {
    int value;
    int idx;
};

void buildTree(int* arr, int* tree, int start, int end, int treeNode){
    if(start == end){
        tree[treeNode] = arr[start];
        return;
    }
    int mid = (start + end)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode + 1);
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode + 1];
    return;
}

void updateTree(int *arr, int *tree, int start, int end, int treeNode, int idx, int value) {
    
    if(start == end) {
        arr[idx] = value;
        tree[treeNode] = value;
        return;
    }
    int mid = (start + end)/2;
    if(idx > mid) updateTree(arr, tree, mid + 1, end, 2*treeNode + 1, idx, value);
    else updateTree(arr, tree, start, mid, 2*treeNode, idx, value);
    
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode + 1];
}
node max_cmp(node a, node b){
    return a.value > b.value ? a : b;
}

node query(int* tree, int start, int end, int treeNode, int left, int right, node exclude) {
    // Completely outside range
    if(start > right || end < left || (start == end && treeNode == exclude.idx)){
        node q;
        q.value = INT_MIN;
        q.idx = -1;
        return q;
    }
    
    // Completely inside
    if(start == end){
        node q;
        q.value = tree[treeNode];
        q.idx = treeNode;
        return q;
    }
    
    // Partially inside and partially outside
    int mid = (start + end)/2;
    node ans1 = query(tree, start, mid, 2*treeNode, left, right, exclude);
    node ans2 = query(tree, mid + 1, end, 2*treeNode + 1, left, right, exclude);
    return max_cmp(ans1, ans2);
}


int main(){
    int n, q;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    int* tree = new int[4*n];
    buildTree(arr, tree, 0, n-1, 1);
    cin >> q;
    while(q--){
        char type;
        int a, b;
        cin >> type >> a >> b;
        if(type == 'U') {
            updateTree(arr, tree, 0, n-1, 1, a-1, b);
        }
        else{
            a -= 1;
            b -= 1;
            node first_max;
            first_max.value = INT_MIN; 
            first_max.idx = -1;
            first_max = query(tree, 0, n-1, 1, a, b, first_max);
            node second_max = query(tree, 0, n-1, 1, a, b, first_max);
            cout <<  first_max.value + second_max.value << endl; 
        }
    }
    
    return 0;
}