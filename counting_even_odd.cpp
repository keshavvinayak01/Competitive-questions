#include<bits/stdc++.h>
using namespace std;

struct node {
    int even, odd;
    node() {
        even = odd = 0;
    }
};

void updateTree(int* arr, node* tree, int start, int end, int treeIndex, int idx, int value) {
    if(start == end) {
        if(value%2 == 0 && arr[idx]%2 != 0) {
            tree[treeIndex].even += 1;
            tree[treeIndex].odd -= 1;
        }
        else if(value%2 != 0 && arr[idx]%2 == 0) {
            tree[treeIndex].even -= 1;
            tree[treeIndex].odd += 1;
        }
        arr[idx] = value;
        return;
    }

    int mid = (start + end)/2;
    
    if(idx > mid) 
        updateTree(arr, tree, mid + 1, end, 2*treeIndex + 1, idx, value);
    else
        updateTree(arr, tree, start, mid, 2*treeIndex, idx, value);

    tree[treeIndex].even = tree[2*treeIndex].even + tree[2*treeIndex + 1].even;
    tree[treeIndex].odd = tree[2*treeIndex].odd + tree[2*treeIndex + 1].odd;
    return;
}

int query(node* tree, int start, int end, int treeIndex, int left, int right, int queryType) {
    if(left > end || right < start) {
        return 0;
    }

    if(start >= left && end <= right) {
        if(queryType == 1)
            return tree[treeIndex].even;
        return tree[treeIndex].odd;
    }
    
    int mid = (start + end)/2;
    int ans1 = query(tree, start, mid, 2*treeIndex, left, right, queryType);
    int ans2 = query(tree, mid + 1, end, 2*treeIndex + 1, left, right, queryType);
    return ans1 + ans2;
}

void buildTree(int* arr, node* tree, int treeIndex, int start, int end) {
    if(start == end) {
        if(arr[start]%2 == 0) {
            tree[treeIndex].even += 1;
        }
        else {
            tree[treeIndex].odd += 1;
        }
        return;
    }

    int mid = (start + end)/2;

    buildTree(arr, tree, 2*treeIndex, start, mid);
    buildTree(arr, tree, 2*treeIndex + 1, mid + 1, end);

    tree[treeIndex].even = tree[2*treeIndex].even + tree[2*treeIndex + 1].even;
    tree[treeIndex].odd = tree[2*treeIndex].odd + tree[2*treeIndex + 1].odd;
    return;
}

int main(){
    int n;
    cin >> n;
    int* a = new int[n];
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    node *tree = new node[3*n];
    buildTree(a, tree, 1, 0, n-1);
    int q;
    cin >> q;
    while(q--) {
        int type, val1, val2;
        cin >> type >> val1 >> val2;
        if(type == 0) {
            updateTree(a, tree, 0, n-1, 1, val1-1, val2);
        }
        else {
            cout << query(tree, 0, n-1, 1, val1-1, val2-1, type) << endl;
        }
    }
    return 0;
}