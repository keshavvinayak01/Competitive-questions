using namespace std;
#include<bits/stdc++.h>

struct Node{
    int data;
    Node* next;
    Node(int n) {
        data = n;
        next = NULL;
    }
};

int getNthFromLast(Node* head, int n) {
    vector<int> x;
    int size = 0;
    Node* current = head;
    while(current) {
        size++;
        x.push_back(current->data);
        current = current->next;
    }
    if(n > size) return -1;
    return x[size-n];
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
    int t, i, n, l, k;
    cin >> t;
    while(t--) {
        Node* head = NULL;
        Node* tail = NULL;
        cin >> n >> k;
        for(i = 1; i <=n ; i++) {
            cin >> l;
            append(&head, &tail, l);
        }
        cout << getNthFromLast(head, k) << endl;
    }
    return 0;   
}