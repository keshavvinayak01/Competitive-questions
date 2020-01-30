#include<bits/stdc++.h>
using namespace std;

struct Node {
    int  data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

int getMiddle(Node* head) {
    int n = 0;
    vector<int> x;
    Node* curr = head;
    while(curr) {
        n++;
        x.push_back(curr->data);
        curr = curr->next;
    }
    return x[n/2];
}


void append(Node** head_ref, Node** tail_ref, int new_data) {
    Node* new_node = new Node(new_data);
    if(*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

int main() {
    int t, i, n, l;
    cin >> t;
    while(t--) {
        Node* head = NULL;
        Node* tail = NULL;
        cin >> n;
        for(int i = 0 ; i < n ; i++) {
            cin >> l;
            append(&head, &tail, l);
        }
        cout << getMiddle(head) << endl;
    }
    return 0;
}