// Find the first non repeating character in string
#include <bits/stdc++.h>
using namespace std;

string find(string s);

//Your code will be place here

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    int x;
	    cin >> x;
	    string s;
	    cin >> s;
	    int h[26];
	    
	    cout << find(s) << "\n";
	    
	}
	
	return 0;
}// } Driver Code Ends


//User function template for C++

// return the first non-repeating char in S.
// if there's no non-repeating char, return "-1"
string find(string S) {
    int map[26];
    memset(map, 0, 26*sizeof(int));
    int n = S.length();
    for(int i = 0 ; i < n; i++)
        map[S[i] - 'a']++;
    for(int i = 0 ; i < n ; i++)
        if(map[S[i] - 'a'] == 1) {
            string ans(1, S[i]);
            return ans;
        }
    return "-1";
}