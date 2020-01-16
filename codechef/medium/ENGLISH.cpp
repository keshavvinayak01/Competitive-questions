#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0)
typedef long long ll;

ll ans = 0;

struct Trie {
    Trie**children;
    int tnodes;

    Trie() {
        children=new Trie*[26];
        for(int i=0;i<26;i++) children[i]=0;
        tnodes=0;
    }
};

int dfs(Trie*root, ll length) {
    if(!root)return 0;
    ll cnt=0;
    
    for(int i=0;i<26;i++) {
        cnt+=dfs(root->children[i],length+1);
    }
    root->tnodes=root->tnodes-cnt;

    if(root->tnodes>1) {
        ll n=(root->tnodes)/2;
        ll temp=(length/2)*(length/2);
        ans+=n*temp;
        cnt+=2*n;
    }

    delete root;
    return cnt;
}


void insertString(string s, Trie*head, char* mixString) {
    Trie*curr=head;
    int idx=0;
    int n=s.length();
    for(int i=0;i<n;i++)
    
    mixString[idx++]=s[i],mixString[idx++]=s[n-i-1];

    for(int i=0;i<2*n;i++) {
        int index = mixString[i]-'a';
        if(curr->children[index] != 0)
            curr = curr->children[index];
        else {
            Trie*child = new Trie();
            curr->children[index] = child;
            curr = curr->children[index];
        }
        curr->tnodes = curr->tnodes+1;
    }
}

int main() {
    fastio;
    char mixString[200010];
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ans = 0;
        string* inputs = new string[n];
        for(int i = 0 ; i < n ; i++) {
            cin >> inputs[i];
        }
        Trie* head = new Trie();
        for(int i = 0 ; i < n ; i++) insertString(inputs[i], head, mixString);
        dfs(head, 0);
        cout << ans << endl;
    }   
    // insertString(s, head);
    return 0;
}