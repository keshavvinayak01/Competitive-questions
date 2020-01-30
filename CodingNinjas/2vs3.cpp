#include<bits/stdc++.h>
using namespace std;

int *dp = new int[10000];
int query(int* tree, int start, int end, int treeIndex, int left, int right) {

    if(left > end || right < start) {
        return 0;
    }
    if(start >= left && end <= right) {
        return tree[treeIndex];
    }
    int mid = (start + end)/2;
    int first = query(tree, start, mid, 2*treeIndex, left, right);
    int second = query(tree, mid + 1, end, 2*treeIndex + 1, left, right);
    return first + second;
}

void updateTree(string s, int* tree, int treeIndex, int start, int end, int idx) {
    if(start == end) {
        s[idx] = '1'; 
        tree[treeIndex] = 1;
        return;
    }
    int mid = (start + end)/2;
    if(idx > mid)   
        updateTree(s, tree, 2*treeIndex+1, mid + 1, end, idx);
    else
        updateTree(s, tree, 2*treeIndex, start, mid, idx);
    int power = pow(2, dp[end-mid]);
    tree[treeIndex] = (tree[2*treeIndex] * power)%3 + tree[2*treeIndex + 1] ;
    return;
}

void buildTree(string s, int* tree, int treeIndex, int start, int end) {
    if(start == end) {
        tree[treeIndex] = s[start] - '0';
        return;
    }
    int mid = (start + end)/2;
    buildTree(s, tree, 2*treeIndex, start, mid);
    buildTree(s, tree, 2*treeIndex + 1, mid + 1, end);
    int power = pow(2, dp[end-mid]);
    tree[treeIndex] = (tree[2*treeIndex] * power)%3 + tree[2*treeIndex + 1] ;
    return;
}

int main(){
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 2;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-2];
    }
    string s;
    cin >> s;
    int* tree = new int[3*n];
    buildTree(s, tree, 1, 0, n-1);
    for(int i = 1; i < 3*n; i++) cout << tree[i] << " " ;
    cout << endl;
    int q;
    cin >> q;
    while(q--) {
        int queryType;
        cin >> queryType;
        if(queryType == 0) {
            int l, r;
            cin >> l >> r;
            int ans =  query(tree, 0, n-1, 1, l, r);
            cout << ans%3 << endl;
        }
        else{
            int x;
            cin >> x;
            updateTree(s, tree, 1, 0, n-1, x);
        }
    }


    return 0;
}