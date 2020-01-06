#include<bits/stdc++.h>
using namespace std;

int* getLps(string pattern) {
    int* lps = new int[pattern.length()];
    lps[0] = 0;
    int i = 1;
    int j = 0;
    while(i < pattern.length()) {
        if(pattern[i] == pattern[j]) {
            lps[i] = j + 1;
            j++; i++;
        }
        else{
            if(j != 0) {
                j = lps[j-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int kmpSearch(string text, string pattern) {
    int lenText = text.length();
    int lenPat = pattern.length();

    int* lps = getLps(pattern);
    int i = 0 ;
    int j = 0;
    while(i < lenText && j < lenPat) {
        if(text[i] == pattern[j]) {
            i++;j++;
            if(j == lenPat) {
                return i - j;
            }
        }
        else{
            if(j != 0) {
                j = lps[j-1];
            }
            else {
                i++;
            }
        }
    }
    
    return -1;   
}
int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;
    cout << kmpSearch(s1, s2);
    return 0;
}