#include<bits/stdc++.h>
using namespace std;

class trieNode {
    public :
        trieNode** children;
    trieNode() {
        children = new trieNode*[26];
        for(int i = 0 ; i < 26 ;i++) children[i] = NULL;
    }
};

void getAllSuggestions(trieNode* current, vector<string> suggestions, int n) {
    int none_counter;
    cout << n << endl;
    for(int i = 0 ; i < 26 ; i++) {
        if(current->children[i]) {
            suggestions[n] += char(i);
            getAllSuggestions(current->children[i], suggestions, n);
        }
        else none_counter++;
    }
    if(none_counter == 26) n++;
}

trieNode* getLastPrefix(string query, trieNode* root) {
    if(query.substr(1).empty()) return root;
    trieNode* child = root->children[query[0] - 'a'];
    getLastPrefix(query.substr(1), child);
    return root;
}

void getSuggestions(string query, string* input, trieNode* root, int n) {
    trieNode* startNode = getLastPrefix(query, root);
    vector<string> suggestions(n);
    for(int i = 0 ; i < n ; i++) suggestions[i] = "";
    cout << "Ran till here\n";
    getAllSuggestions(startNode, suggestions, 0);

    for(int i = 0 ; i < suggestions.size(); i++) {
        if(suggestions[i].size() > 0)
            cout << suggestions[i] << endl;        
    }
}

void insertTrie(trieNode* root, string input, int n) {
    if(input.empty()) return;
    trieNode* child;
    int index = input[0] - 'a';
    if(root->children[index]) {
        child = root->children[index];
    }
    else {
        child = new trieNode();
        root->children[index] = child;
    }
    insertTrie(child, input.substr(1), n);
}

int main() {
    int n, q;
    cin >> n;
    string* input = new string[n];
    for(int i = 0 ; i < n ; i++) {
        cin >> input[i];
    }
    trieNode* root = new trieNode();
    for(int i = 0 ; i < n ; i++) {
        insertTrie(root, input[i], n);
    }
    cin >> q;
    for(int i = 0 ; i < q ; i++) {
        string query;
        cin >> query;
        getSuggestions(query, input, root, n);
    }
    return 0;
}