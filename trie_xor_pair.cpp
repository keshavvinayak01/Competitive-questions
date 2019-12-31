#include<bits/stdc++.h>
using namespace std;

struct trieNode {
    
    trieNode* left;
    trieNode* right;
};

void insert(int n, trieNode* head) {
    trieNode* current = head;
    for(int i = 31; i >= 0; i--) {
        int b = (n >> i) & 1;

        if(b == 0) {
            if(!current->left) {
                current->left = new trieNode;
            }
            current = current->left;
        }
        else {
            if(!current->right) {
                current->right = new trieNode;
            }
            current = current->right;
        }
    }
}

int findMaxXorPair(trieNode* head, int* arr, int n) {
    int max_xor = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        int value = arr[i];
        int curr_xor = 0;
        trieNode* current = head;
        for(int j = 31; j >= 0; j--) {
            int b = (value >> j) & 1;
            if(b == 0) {
                if(current->right) {
                    curr_xor += pow(2,j);
                    current = current->right;
                }
                else {
                    current = current->left;
                }
            }
            else {
                if(current->left) {
                    curr_xor += pow(2,j);
                    current = current->left;
                }
                else {
                    current = current->right;
                }
            }
        }
        if(curr_xor > max_xor) max_xor = curr_xor;
    }
    return max_xor;
}

int main() {
    int arr[6] = {8,1,2,15,10,5};
    trieNode* head = new trieNode();
    for(int i = 0; i < 6 ; i++) {
        insert(arr[i], head);
    }
    cout << findMaxXorPair(head, arr, 6) << endl;
    return 0;
}