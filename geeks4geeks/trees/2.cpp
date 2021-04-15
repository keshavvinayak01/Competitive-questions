/*
Given a full binary expression tree consisting of basic binary operators (+ , – ,*, /) and some integers, 
Your task is to evaluate the expression tree.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct node {
    string data;
    struct node *left;
    struct node *right;

    node(string x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

bool isExpression(string &s) {
    if (s == "+" or s == "-" or s == "*" or s == "/") return true;
    return false;
}



 // } Driver Code Ends
/*The structure of node is as follows
struct node{
    string data;
    node *left;
    node *right;
};
*/

class Solution{
  public:
  
    int convInt(string s) {
        stringstream s1(s);
        int x;
        s1 >> x;
        return x;
    }
    
    int evalExp(int a, int b, string op) {
        if(op == "+") return a + b;
        else if(op == "-") return a - b;
        else if(op == "*") return a * b;
        else return a / b;
    }
    
    /*You are required to complete below method */
    int evalTree(node* root) {
        if(!(root->data == "+" || root->data == "-" ||
             root->data == "*" || root->data == "/")) return convInt(root->data);
        else {
            int leftExp = evalTree(root->left);
            int rightExp = evalTree(root->right);
            return evalExp(leftExp, rightExp, root->data);
        }
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        int p = 0;
        node *root = new node(s[p++]);
        queue<node *> q;
        q.push(root);
        while (!q.empty()) {
            node *f = q.front();
            q.pop();
            node *l, *r;
            if (isExpression(f->data)) {
                l = new node(s[p++]);
                r = new node(s[p++]);
                f->left = l;
                f->right = r;
                q.push(l);
                q.push(r);
            }
        }
        Solution obj;
        cout << obj.evalTree(root) << endl;
    }
}
  // } Driver Code Ends