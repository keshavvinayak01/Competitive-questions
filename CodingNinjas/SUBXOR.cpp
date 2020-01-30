#include<bits/stdc++.h>
using namespace std;

class trieNode{

public:
	int lvalue = 0;
	int rvalue = 0;
	trieNode* left;
	trieNode* right;
};

void insert(int n, trieNode* head){

	trieNode* curr = head;

	for(int i = 31; i >= 0; i--){
		int b = (n>>i)&1;

		if(b == 0){

			if(!curr->left){
				curr->left = new trieNode();
			}
			curr->lvalue++;
			curr = curr->left;

		}else{

			if(!curr->right){
				curr->right = new trieNode();
			}
			curr->rvalue++;
			curr = curr->right;
		}
	}
}

int query(trieNode* head, int value, int K){

	trieNode* curr = head;
	int count = 0;
	for(int j = 31; j >= 0; j--){
		int b = (value >> j)&1;
		int k = (K >> j)&1;

		if(b==1 && k== 1){
			count += curr->rvalue;
			if(curr->left)
				curr = curr->left;
            else
                break;
		}
		else if(b==1 && k == 0){
			if(curr->right)
				curr = curr->right;
            else
                break;
		}
		else if(b==0 && k == 1){
			count += curr->lvalue;
			if(curr->right)
				curr = curr->right;
            else 
                break;
		}
		else{
			if(curr->left)
				curr = curr->left;
            else 
                break;
		}
	}
	return count;
}



long long int SubXOR(trieNode* head, int* arr, int n, int k){

	long long int count = 0;
	int curr = 0;
    
    insert(0,head);
	for(int i = 0; i < n; i++){
		curr = curr ^ arr[i];
        int curr_ans = query(head, curr, k);
		insert(curr, head);
		count += curr_ans;
	}
	
	return count;
}

int main(){

	int t;
	cin  >>t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int arr[n];
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		trieNode* head = new trieNode();

		cout << SubXOR(head, arr, n, k) << endl;
	}
}

