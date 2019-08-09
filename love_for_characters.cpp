#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,int> counts;
    // counts.insert(pair<char,int>('a',0));
    // counts.insert(pair<char,int>('s',0));
    // counts.insert(pair<char,int>('p',0));
    counts['a'] = 0;
    counts['s'] = 0;
    counts['p'] = 0;
    for(int i=0; i<n; i++){
        if(s[i] == 'a' || s[i] == 's' || s[i] == 'p'){
            counts[s[i]] = counts[s[i]] + 1;
        }
    }
    cout<<counts['a']<<" "<<counts['s']<<" "<<counts['p']<<endl;    
	return 0;
}
