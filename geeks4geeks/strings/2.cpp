/*
    Given 2 strings needle and haystack. Return the index of the first occurrence of needle in haystack. 
    If needle is not part of haystack return -1. If needle is empty return 0.
*/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
int NeedleinHaystack(string haystack, string needle) ;


 // } Driver Code Ends
//User function Template for C++

int NeedleinHaystack(string haystack, string needle)  {
    int pos = -1, j;
    bool found = false;
    for(int i = 0 ; i < haystack.size() - needle.size() + 1; i++) {
        j = 0;
        while(j < needle.size() && needle[j] == haystack[j + i]) {
            j++;
        }
        if(j == needle.size()) {
            found = true;
            pos = i;
            break;
        }
    }
    if(found) return pos;
    else      return -1;
    // Your code goes here 
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string haystack, needle;
        getline(cin,haystack);
        getline(cin,needle);
        cout<<NeedleinHaystack(haystack,needle)<<"\n";
    }
    return 0;
}  // } Driver Code Ends