#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    ll a, b, res;
    node(){
        a = b = 0;
        res = 1000005;
    }
};

void buildTree(node* arr, node*tree, int treeIndex, int start, int end) {
    if(start == end) {
        tree[treeIndex].a = arr[start].a;
        tree[treeIndex].b = arr[start].b;
        tree[treeIndex].res = start;
        return;
    }
    int mid = (start + end)/2;
    buildTree(arr, tree, 2*treeIndex, start, mid);
    buildTree(arr, tree, 2*treeIndex + 1, mid + 1, end);

    node left = tree[2*treeIndex];
    node right = tree[2*treeIndex + 1];

    if(left.a > right.a) {
        tree[treeIndex].a = left.a;
        tree[treeIndex].b = left.b;
        tree[treeIndex].res = left.res;
    }
    else if(left.a < right.a) {
        tree[treeIndex].a = right.a;
        tree[treeIndex].b = right.b;
        tree[treeIndex].res = right.res;
    }
    else {
        if(left.b < right.b) {
            tree[treeIndex].a = left.a;
            tree[treeIndex].b = left.b;
            tree[treeIndex].res = left.res;
        }
        else if(left.b > right.b) {
            tree[treeIndex].a = right.a;
            tree[treeIndex].b = right.b;
            tree[treeIndex].res = right.res;
        }
        else {
            tree[treeIndex].a = left.a;
            tree[treeIndex].b = left.b;
            tree[treeIndex].res = left.res;
        }
    }
    return;
}

node query(node* tree, int start, int end, int treeIndex, int left, int right) {
    if(start > right || end < left) {
        node temp;
        temp.a = 0;
        temp.b = 100005;
        temp.res = -1;
        return temp;
    }
    if(start >= left && end <= right) {
        return tree[treeIndex];
    }
    int mid = (start + end)/2;
    node first = query(tree, start, mid, 2*treeIndex, left, right);
    node second = query(tree, mid + 1, end, 2*treeIndex + 1, left, right);

    if(first.a > second.a) {
        return first;
    }
    else if(first.a < second.a) {
        return second;
    }
    else {
        if(first.b < second.b) {
            return first;
        }
        else if(first.b > second.b) {
            return second;
        }
        else {
            return first;
        }
    }
}

int main(){
    int n;
    cin >> n;
    node* arr = new node[n];
    for(int i = 0; i < n; i++) cin >> arr[i].a;
    for(int i = 0; i < n; i++) cin >> arr[i].b;
    node* tree = new node[4*n];
    buildTree(arr, tree, 1, 0, n-1);

    
    int q;
    cin >> q;
    while(q--) {
        int left, right;
        cin >> left >> right;
        node ans = query(tree, 0, n-1, 1, left-1, right-1);
        cout << ans.res + 1 << endl;
    }
    return 0;
}