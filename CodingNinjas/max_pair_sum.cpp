#include<bits/stdc++.h>
using namespace std;

struct node {
    int maximum;
    int smaxmimum;
};

void updateNode(node* tree, int treeIndex) {
    node left = tree[2*treeIndex];
    node right = tree[2*treeIndex + 1];
    tree[treeIndex].maximum = max(left.maximum, right.maximum);
    tree[treeIndex].smaxmimum = min(max(left.maximum, right.smaxmimum), max(left.smaxmimum, right.maximum));
    return;
}

void buildTree(int* arr, node* tree, int treeIndex, int start, int end) {
    if(start == end) {
        tree[treeIndex].maximum = arr[start];
        tree[treeIndex].smaxmimum = INT_MIN;
        return;
    }
    int mid = (start + end)/2;
    buildTree(arr, tree, 2*treeIndex, start, mid);
    buildTree(arr, tree, 2*treeIndex + 1, mid+1, end);

    updateNode(tree, treeIndex);
    return;
}

node query(node* tree, int start, int end, int treeNode, int left, int right) {
    // Completely outside range
    if(start > right || end < left) {
        node t;
        t.maximum = INT_MIN;
        t.smaxmimum = INT_MIN;
        return t;
    }
    // Completely inside
    if(start >= left && end <= right){
        return tree[treeNode];
    };
    
    // Partially inside and partially outside
    int mid = (start + end)/2;
    node ans1 = query(tree, start, mid, 2*treeNode, left, right);
    node ans2 = query(tree, mid + 1, end, 2*treeNode + 1, left, right);
    node ans;
    if(ans1.maximum > ans2.maximum){
        ans.maximum = ans1.maximum;
        ans.smaxmimum = max(ans1.smaxmimum, ans2.maximum);
    }
    else{
        ans.maximum = ans2.maximum;
        ans.smaxmimum = max(ans2.smaxmimum, ans1.maximum);
    }
    return ans;
}

void updateTree(int* arr, node* tree, int start, int end, int treeIndex, int idx, int value) {
    // Completely outside range
    if(start == end) {
        arr[idx] = value;
        tree[treeIndex].maximum = value;
        tree[treeIndex].smaxmimum = INT_MIN;
        return;
    }
    int mid = (start + end)/2;
    
    if(idx > mid) updateTree(arr, tree, mid + 1, end, 2*treeIndex + 1, idx, value);
    else          updateTree(arr, tree, start, mid, 2*treeIndex, idx, value);
    
    updateNode(tree, treeIndex);
}

int main(){
    int n, q;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    node* tree = new node[3*n];
    buildTree(arr, tree, 1, 0, n-1);
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
            node max_sum = query(tree, 0, n-1, 1, a, b);
            cout << max_sum.maximum + max_sum.smaxmimum << endl; 
        }
    }
    
    return 0;
}