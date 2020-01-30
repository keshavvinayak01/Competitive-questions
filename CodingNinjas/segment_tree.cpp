#include<bits/stdc++.h>
using namespace std;


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

int query(int* tree, int start, int end, int treeNode, int left, int right) {
    // Completely outside range
    if(start > right || end < left) return 0;
    
    // Completely inside
    if(start >= left && end <= right) return tree[treeNode];
    
    // Partially inside and partially outside
    int mid = (start + end)/2;
    int ans1 = query(tree, start, mid, 2*treeNode, left, right);
    int ans2 = query(tree, mid + 1, end, 2*treeNode + 1, left, right);
    return ans1 + ans2;
}

int minInRange(int* tree, int start, int end, int treeNode, int left, int right) {
    // Completely outside range
    if(start > right || end < left) return INT_MAX;
    
    // Completely inside
    if(start >= left && end <= right) return tree[treeNode];
    
    // Partially inside and partially outside
    int mid = (start + end)/2;
    int ans1 = query(tree, start, mid, 2*treeNode, left, right);
    int ans2 = query(tree, mid + 1, end, 2*treeNode + 1, left, right);
    return min(ans1, ans2);
}

int main(){

    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int* tree = new int[10];

    buildTree(arr, tree, 0, 8, 1);
    updateTree(arr, tree, 0, 4, 1, 2, 10);
    
    return 0;
}