#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    map<char, char> dict;
    dict['_'] = ' ';
    string s;
    cin >> t >> s;
    for(int i = 0 ; i < s.size(); i++) dict[char(97 + i)] = s[i];
    while(t--) {
        string sentence, newSentence = "";
        cin >> sentence;
        for(int i = 0 ; i < sentence.size(); i++) {
            if(isupper(sentence[i])) {
                newSentence += toupper(dict[tolower(sentence[i])]); 
            }

            else if(dict[sentence[i]] == '\0') newSentence += sentence[i];
            
            else newSentence += dict[sentence[i]];
        }
        cout << newSentence << endl;
    }
    return 0;
}