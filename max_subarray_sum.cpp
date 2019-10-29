#include<bits/stdc++.h>
using namespace std;

struct node {
    int maxSum, bss, bps, totalSum;
};
void print_node(node a) {
    cout << a.maxSum << " " << a.bss << " " << a.bps << " " << a.totalSum << endl;
}
void buildTree(int* arr, node* tree, int treeIndex, int start, int end) {
    if(start == end) {
        tree[treeIndex].totalSum = arr[start];
        tree[treeIndex].bss = arr[start];
        tree[treeIndex].maxSum = arr[start];
        tree[treeIndex].bps = arr[start];
        return;
    }

    int mid = (start + end)/2;
    buildTree(arr, tree, 2*treeIndex, start, mid);
    buildTree(arr, tree, 2*treeIndex + 1, mid + 1, end);

    node left = tree[2*treeIndex];
    node right = tree[2*treeIndex + 1];
    tree[treeIndex].totalSum = left.totalSum + right.totalSum;
    tree[treeIndex].bps = max(left.bps, left.totalSum + right.bps);
    tree[treeIndex].bss = max(right.bss, right.totalSum + left.bss);
    tree[treeIndex].maxSum = max(left.maxSum, max(right.maxSum, max(left.totalSum + right.bps, max(right.totalSum + left.bss, max(left.totalSum + right.totalSum, left.bss + right.bps)))));
    return;
}
node query(node* tree, int start, int end, int treeNode, int left, int right) {
    // Completely outside range
    if(start > right || end < left){
        node temp;
        temp.totalSum = temp.bps = temp.bss = temp.maxSum = INT_MIN;
        return temp;
    }
    
    // Completely inside
    if(start >= left && end <= right) return tree[treeNode];
    
    // Partially inside and partially outside
    int mid = (start + end)/2;
    node ans1 = query(tree, start, mid, 2*treeNode, left, right);
    node ans2 = query(tree, mid + 1, end, 2*treeNode + 1, left, right);
    node ans;
    ans.totalSum = ans1.totalSum + ans2.totalSum;
    ans.bps = max(ans1.bps, ans1.totalSum + ans2.bps);
    ans.bss = max(ans2.bss, ans2.totalSum + ans1.bss);
    ans.maxSum = max(ans1.maxSum, max(ans2.maxSum, max(ans1.totalSum + ans2.bps, max(ans2.totalSum + ans1.bss, max(ans1.maxSum + ans2.maxSum, ans1.bss + ans2.bps)))));
    print_node(ans);
    return ans;
}

int main(){
    int n, q;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    
    node* tree = new node[4*n];
    buildTree(a, tree, 1, 0, n-1);
    for(int i = 0 ; i < 3*n; i++) print_node(tree[i]);
    cout << endl;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        node ans = query(tree, 0, n-1, 1, a-1, b-1);
        cout << ans.maxSum << endl;
    }

    return 0;
}